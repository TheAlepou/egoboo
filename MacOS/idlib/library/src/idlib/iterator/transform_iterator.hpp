///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Idlib: A C++ utility library
// Copyright (C) 2017-2018 Michael Heilmann
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `range.hpp` instead)
#endif

#include "iterator.hpp"
#include "platform.hpp"

#ifdef __cplusplus

// STL
#include <iterator>
#include <type_traits>
#include <utility>

#include "header.in"   // opens namespace idlib

// Forward declaration (inside idlib)
template <typename UnaryFunctor, typename Iterator>
struct transform_iterator;

#include "footer.in"   // closes namespace idlib

// ---- Define the iterator (inside idlib) ----
#include "header.in"

template <typename UnaryFunctor, typename Iterator>
struct transform_iterator
{
    using my_type = transform_iterator<UnaryFunctor, Iterator>;
    using iterator_type = Iterator;
    using unary_functor_type = UnaryFunctor;

    using source_iterator_category = typename std::iterator_traits<Iterator>::iterator_category;

    // Traits of *this* iterator will be provided by std::iterator_traits specialization (below).
    using my_iterator_traits = std::iterator_traits<my_type>;
    using value_type        = typename my_iterator_traits::value_type;
    using reference         = typename my_iterator_traits::reference;
    using pointer           = typename my_iterator_traits::pointer;
    using difference_type   = typename my_iterator_traits::difference_type;

    iterator_type     m_it{};
    unary_functor_type m_fn{};

    transform_iterator() = default;
    transform_iterator(iterator_type it, unary_functor_type fn) : m_it(it), m_fn(fn) {}

private:
    void increment() { ++m_it; }

    // bidirectional decrement
    std::enable_if_t<
        std::is_base_of<std::bidirectional_iterator_tag, source_iterator_category>::value, void>
    decrement()
    { --m_it; }

    // random-access += n
    std::enable_if_t<
        std::is_base_of<std::random_access_iterator_tag, source_iterator_category>::value, void>
    increment(difference_type n)
    { m_it += n; }

    // random-access -= n
    std::enable_if_t<
        std::is_base_of<std::random_access_iterator_tag, source_iterator_category>::value, void>
    decrement(difference_type n)
    { m_it -= n; }

    bool equal(const transform_iterator& other) const { return m_it == other.m_it; }

public:
    transform_iterator(const transform_iterator&) = default;
    transform_iterator& operator=(const transform_iterator&) = default;

    bool operator==(const transform_iterator& other) const { return equal(other); }
    bool operator!=(const transform_iterator& other) const { return !(*this == other); }

    // bidirectional --it
    std::enable_if_t<
        std::is_base_of<std::bidirectional_iterator_tag, source_iterator_category>::value, transform_iterator&>
    operator--()
    { decrement(); return *this; }

    // bidirectional it--
    std::enable_if_t<
        std::is_base_of<std::bidirectional_iterator_tag, source_iterator_category>::value, transform_iterator>
    operator--(int)
    { auto it = *this; --(*this); return it; }  // (fix: use --, not ++)

    // random-access it += n
    std::enable_if_t<
        std::is_base_of<std::random_access_iterator_tag, source_iterator_category>::value, transform_iterator&>
    operator+=(difference_type n)
    { increment(n); return *this; }

    // random-access it -= n
    std::enable_if_t<
        std::is_base_of<std::random_access_iterator_tag, source_iterator_category>::value, transform_iterator&>
    operator-=(difference_type n)
    { decrement(n); return *this; }

    // random-access it + n
    std::enable_if_t<
        std::is_base_of<std::random_access_iterator_tag, source_iterator_category>::value, transform_iterator>
    operator+(difference_type n) const
    { auto it = *this; it.increment(n); return it; }

    // random-access it - n
    std::enable_if_t<
        std::is_base_of<std::random_access_iterator_tag, source_iterator_category>::value, transform_iterator>
    operator-(difference_type n) const
    { auto it = *this; it.decrement(n); return it; }

    // ++it / it++
    transform_iterator& operator++() { increment(); return *this; }
    transform_iterator  operator++(int) { auto it = *this; ++(*this); return it; }

    // *it
    reference operator*() const { return m_fn(*m_it); }

    iterator_type&       get_it()       { return m_it; }
    iterator_type const& get_it() const { return m_it; }
};

#include "footer.in"   // closes namespace idlib

// ---- Specialize std::iterator_traits for idlib::transform_iterator ----
namespace std {

template <typename UnaryFunctor, typename Iterator>
struct iterator_traits<idlib::transform_iterator<UnaryFunctor, Iterator>>
{
    // result of applying the functor to the underlying reference
    using reference = std::invoke_result_t<const UnaryFunctor&, typename std::iterator_traits<Iterator>::reference>;
    using value_type = std::remove_cv_t<std::remove_reference_t<reference>>;
    using pointer = std::add_pointer_t<value_type>;
    using difference_type = typename std::iterator_traits<Iterator>::difference_type;
    using iterator_category = typename std::iterator_traits<Iterator>::iterator_category;
};

} // namespace std

#endif
