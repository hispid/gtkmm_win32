// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gdkmm/rectangle.h>
#include <gdkmm/private/rectangle_p.h>

#include <cstring> // std::memset()

/*
 * Copyright 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

namespace Gdk
{

Rectangle::Rectangle(int x, int y, int width, int height)
{
  gobject_.x = x;
  gobject_.y = y;
  gobject_.width  = width;
  gobject_.height = height;
}

// gdk_rectangle_union() and gdk_rectangle_intersect() work fine even if
// the destination points to one of the input rectangles.  The join() and
// intersect() implementations rely on this ability.

Rectangle& Rectangle::join(const Rectangle& src2)
{
  gdk_rectangle_union(
      &gobject_, const_cast<GdkRectangle*>(&src2.gobject_), &gobject_);
  return *this;
}

Rectangle& Rectangle::intersect(const Rectangle& src2)
{
  gdk_rectangle_intersect(
      &gobject_, const_cast<GdkRectangle*>(&src2.gobject_), &gobject_);
  return *this;
}

Rectangle& Rectangle::intersect(const Rectangle& src2, bool& rectangles_intersect)
{
  rectangles_intersect = gdk_rectangle_intersect(
      &gobject_, const_cast<GdkRectangle*>(&src2.gobject_), &gobject_);
  return *this;
}

bool Rectangle::intersects(const Rectangle& src2) const
{
  return gdk_rectangle_intersect(&gobject_, &src2.gobject_, 0);
}

bool Rectangle::has_zero_area() const
{
  return (gobject_.width == 0 || gobject_.height == 0);
}

// Freestanding functions (not Rectangle members)

Rectangle join(const Rectangle& src1, const Rectangle& src2)
{
  Rectangle dest;
  gdk_rectangle_union(src1.gobj(), src2.gobj(), dest.gobj());
  return dest;
}

Rectangle intersect(const Rectangle& src1, const Rectangle& src2)
{
  Rectangle dest;
  gdk_rectangle_intersect(src1.gobj(), src2.gobj(), dest.gobj());
  return dest;
}

Rectangle intersect(const Rectangle& src1, const Rectangle& src2, bool& rectangles_intersect)
{
  Rectangle dest;
  rectangles_intersect = gdk_rectangle_intersect(src1.gobj(), src2.gobj(), dest.gobj());
  return dest;
}

} // namespace Gdk


namespace
{
} // anonymous namespace


namespace Glib
{

Gdk::Rectangle& wrap(GdkRectangle* object)
{
  return *reinterpret_cast<Gdk::Rectangle*>(object);
}

const Gdk::Rectangle& wrap(const GdkRectangle* object)
{
  return *reinterpret_cast<const Gdk::Rectangle*>(object);
}

} // namespace Glib


namespace Gdk
{


Rectangle::Rectangle(const Rectangle& other) noexcept
:
  gobject_(other.gobject_)
{
}

Rectangle& Rectangle::operator=(const Rectangle& other) noexcept
{
  gobject_ = other.gobject_;
  return *this;
}

Rectangle::Rectangle(Rectangle&& other) noexcept
:
  gobject_(std::move(other.gobject_))
{
  //We could wipe other.gobject_ via memset,
  //but that is not really necessary:
  //other.gobject_ = nullptr;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept
{
  gobject_ = std::move(other.gobject_);
  return *this;
}

// static
GType Rectangle::get_type()
{
  return gdk_rectangle_get_type();
}

Rectangle::Rectangle()
{
  std::memset(&gobject_, 0, sizeof(GdkRectangle));
}

Rectangle::Rectangle(const GdkRectangle* gobject)
{
  if(gobject)
    gobject_ = *gobject;
  else
    std::memset(&gobject_, 0, sizeof(GdkRectangle));
}


 int Rectangle::get_x() const
{
  return gobj()->x;
}
 
 void Rectangle::set_x(const int& value)
{
  gobj()->x = value;
}
 
 int Rectangle::get_y() const
{
  return gobj()->y;
}
 
 void Rectangle::set_y(const int& value)
{
  gobj()->y = value;
}
 
 int Rectangle::get_width() const
{
  return gobj()->width;
}
 
 void Rectangle::set_width(const int& value)
{
  gobj()->width = value;
}
 
 int Rectangle::get_height() const
{
  return gobj()->height;
}
 
 void Rectangle::set_height(const int& value)
{
  gobj()->height = value;
}
 

} // namespace Gdk


