// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gdkmm/pixbufformat.h>
#include <gdkmm/private/pixbufformat_p.h>


/* Copyright (C) 2002 The gtkmm Development Team
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

#include <gdk-pixbuf/gdk-pixbuf.h>

namespace Gdk
{

PixbufFormat::PixbufFormat()
: gobject_(0) //because only a gdk-pixbuf backend can create them.
{
}

} // namespace Gdk

namespace
{
} // anonymous namespace


namespace Glib
{

Gdk::PixbufFormat wrap(GdkPixbufFormat* object, bool take_copy)
{
  return Gdk::PixbufFormat(object, take_copy);
}

} // namespace Glib


namespace Gdk
{


// static
GType PixbufFormat::get_type()
{
  return gdk_pixbuf_format_get_type();
}


PixbufFormat::PixbufFormat(const PixbufFormat& other)
:
  gobject_ ((other.gobject_) ? gdk_pixbuf_format_copy(other.gobject_) : 0)
{}

PixbufFormat::PixbufFormat(PixbufFormat&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

PixbufFormat& PixbufFormat::operator=(PixbufFormat&& other) noexcept
{
  PixbufFormat temp (other);
  swap(temp);
  return *this;
}

PixbufFormat::PixbufFormat(GdkPixbufFormat* gobject, bool make_a_copy)
:
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.
  gobject_ ((make_a_copy && gobject) ? gdk_pixbuf_format_copy(gobject) : gobject)
{}

PixbufFormat& PixbufFormat::operator=(const PixbufFormat& other)
{
  PixbufFormat temp (other);
  swap(temp);
  return *this;
}

PixbufFormat::~PixbufFormat() noexcept
{
  if(gobject_)
    gdk_pixbuf_format_free(gobject_);
}

void PixbufFormat::swap(PixbufFormat& other) noexcept
{
  GdkPixbufFormat *const temp = gobject_;
  gobject_ = other.gobject_;
  other.gobject_ = temp;
}

GdkPixbufFormat* PixbufFormat::gobj_copy() const
{
  return gdk_pixbuf_format_copy(gobject_);
}


Glib::ustring PixbufFormat::get_name() const
{
  return Glib::convert_return_gchar_ptr_to_ustring(gdk_pixbuf_format_get_name(const_cast<GdkPixbufFormat*>(gobj())));
}

Glib::ustring PixbufFormat::get_description() const
{
  return Glib::convert_return_gchar_ptr_to_ustring(gdk_pixbuf_format_get_description(const_cast<GdkPixbufFormat*>(gobj())));
}

std::vector<Glib::ustring> PixbufFormat::get_mime_types() const
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(gdk_pixbuf_format_get_mime_types(const_cast<GdkPixbufFormat*>(gobj())), Glib::OWNERSHIP_DEEP);
}

std::vector<Glib::ustring> PixbufFormat::get_extensions() const
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(gdk_pixbuf_format_get_extensions(const_cast<GdkPixbufFormat*>(gobj())), Glib::OWNERSHIP_DEEP);
}

bool PixbufFormat::is_writable() const
{
  return gdk_pixbuf_format_is_writable(const_cast<GdkPixbufFormat*>(gobj()));
}

bool PixbufFormat::is_scalable() const
{
  return gdk_pixbuf_format_is_scalable(const_cast<GdkPixbufFormat*>(gobj()));
}

bool PixbufFormat::is_disabled() const
{
  return gdk_pixbuf_format_is_disabled(const_cast<GdkPixbufFormat*>(gobj()));
}

void PixbufFormat::set_disabled(bool disabled)
{
  gdk_pixbuf_format_set_disabled(gobj(), static_cast<int>(disabled));
}

Glib::ustring PixbufFormat::get_license() const
{
  return Glib::convert_return_gchar_ptr_to_ustring(gdk_pixbuf_format_get_license(const_cast<GdkPixbufFormat*>(gobj())));
}


} // namespace Gdk


