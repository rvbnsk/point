#ifndef PNT_POINT_HPP
#define PNT_POINT_HPP

#include <concepts>
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <utility>
#include <vector>

namespace pnt {

template <typename T, std::size_t N>
class Point {
   private:
    std::vector<T, N> point;

   public:
    Point();
    ~Point() = default;

    Point(const Point<T, N> &point);
    Point(Point<T, N> &&point) noexcept;

    template <typename U, std::size_t M>
    explicit Point(const Point<U, M> &point);

    template <typename U, std::size_t M>
    explicit Point(Point<U, M> &&points) noexcept;

    auto operator=(const Point<T, N> &point) -> Point<T, N> &;
    auto operator=(Point<T, N> &&point) noexcept -> Point<T, N> &;

    template <typename U, std::size_t M>
    auto operator=(const Point<U, M> &point) -> Point<T, N> &;

    template <typename U, std::size_t M>
    auto operator=(Point<U, M> &&point) noexcept -> Point<T, N> &;
};

}  // namespace pnt

#endif  // PNT_POINT_HPP