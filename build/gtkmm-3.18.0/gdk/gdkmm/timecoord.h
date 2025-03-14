// -*- c++ -*-
// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!
#ifndef _GDKMM_TIMECOORD_H
#define _GDKMM_TIMECOORD_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2011 The gtkmm Development Team
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

#include <gdk/gdk.h>


namespace Gdk
{

/** A Gdk::TimeCoord instance contains a single event of motion history.
 * You shouldn't be using it as a standalone object.
 */
class TimeCoord
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef TimeCoord CppObjectType;
  typedef GdkTimeCoord BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

public:
  explicit TimeCoord(GdkTimeCoord* castitem);

  //TODO: = delete the copy operations?

  TimeCoord(TimeCoord&& other) noexcept;
  TimeCoord& operator=(TimeCoord&& other) noexcept;

   guint32 get_time() const;
 
  /** Gets value at @a index axis.
   * @note
   * Gdk::Device::get_n_axes() will tell you how many axes are stored here.
   *
   * @param index Index of an axis from which the value will be taken.
   * @return A value at @a index.
   */
  double get_value_at_axis(guint index) const;

  ///Provides access to the underlying C object.
  GdkTimeCoord* gobj() {return gobject_;}
  ///Provides access to the underlying C object.
  const GdkTimeCoord* gobj() const {return gobject_;}
protected:
  GdkTimeCoord* gobject_;


};

#ifndef DOXYGEN_SHOULD_SKIP_THIS
struct TimeCoordPtrTraits
{
  typedef Gdk::TimeCoord CppType;
  typedef GdkTimeCoord* CType;
  typedef GdkTimeCoord* CTypeNonConst;

  static CType to_c_type(const CppType& obj) { return const_cast<CType>(obj.gobj()); }
  static CType to_c_type(const CType& obj) { return obj; }
  static CppType to_cpp_type(const CType& obj) { return CppType(const_cast<CType>(obj)); }
  static void release_c_type(const CType& obj) { g_free(const_cast<CType>(obj)); }
};
#endif

} // namespace Gdk


#endif /* _GDKMM_TIMECOORD_H */

