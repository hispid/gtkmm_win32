// Generated by gmmproc 2.46.3 -- DO NOT MODIFY!


#include <glibmm.h>

#include <glibmm/fileutils.h>
#include <glibmm/private/fileutils_p.h>


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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <glib.h>
#include <glibmm/utility.h>


namespace Glib
{

/**** Glib::Dir ************************************************************/

Dir::Dir(const std::string& path)
{
  GError* error = nullptr;
  gobject_ = g_dir_open(path.c_str(), 0, &error);

  if(error)
    Glib::Error::throw_exception(error);
}

Dir::Dir(GDir* gobject)
:
  gobject_ (gobject)
{}

Dir::~Dir()
{
  if(gobject_)
    g_dir_close(gobject_);
}

std::string Dir::read_name()
{
  const char *const name = g_dir_read_name(gobject_);
  return Glib::convert_const_gchar_ptr_to_stdstring(name);
}

void Dir::rewind()
{
  g_dir_rewind(gobject_);
}

void Dir::close()
{
  if(gobject_)
  {
    g_dir_close(gobject_);
    gobject_ = nullptr;
  }
}

DirIterator Dir::begin()
{
  g_dir_rewind(gobject_);
  return DirIterator(gobject_, g_dir_read_name(gobject_));
}

DirIterator Dir::end()
{
  return DirIterator(gobject_, 0);
}


/**** Glib::DirIterator ****************************************************/

DirIterator::DirIterator()
:
  gobject_ (0),
  current_ (0)
{}

DirIterator::DirIterator(GDir* gobject, const char* current)
:
  gobject_ (gobject),
  current_ (current)
{}

std::string DirIterator::operator*() const
{
  return convert_const_gchar_ptr_to_stdstring(current_);
}

DirIterator& DirIterator::operator++()
{
  current_ = g_dir_read_name(gobject_);
  return *this;
}

void DirIterator::operator++(int)
{
  current_ = g_dir_read_name(gobject_);
}

bool DirIterator::operator==(const DirIterator& rhs) const
{
  return (current_ == rhs.current_);
}

bool DirIterator::operator!=(const DirIterator& rhs) const
{
  return (current_ != rhs.current_);
}


bool file_test(const std::string& filename, FileTest test)
{
  return g_file_test(filename.c_str(), static_cast<GFileTest>(unsigned(test)));
}

int mkstemp(std::string& filename_template)
{
  const ScopedPtr<char> buf (g_strndup(filename_template.data(), filename_template.size()));
  const auto fileno = g_mkstemp(buf.get());

  filename_template = buf.get();
  return fileno;
}

int file_open_tmp(std::string& name_used, const std::string& prefix)
{
  std::string basename_template (prefix);
  basename_template += "XXXXXX"; // this sillyness shouldn't be in the interface

  GError* error = nullptr;
  ScopedPtr<char> buf_name_used;

  const auto fileno = g_file_open_tmp(basename_template.c_str(), buf_name_used.addr(), &error);

  if(error)
    Glib::Error::throw_exception(error);

  name_used = buf_name_used.get();
  return fileno;
}

int file_open_tmp(std::string& name_used)
{
  GError* error = nullptr;
  ScopedPtr<char> buf_name_used;

  const auto fileno = g_file_open_tmp(0, buf_name_used.addr(), &error);

  if(error)
    Glib::Error::throw_exception(error);

  name_used = buf_name_used.get();
  return fileno;
}

std::string file_get_contents(const std::string& filename)
{
  ScopedPtr<char> contents;
  gsize   length = 0;
  GError* error  = nullptr;

  g_file_get_contents(filename.c_str(), contents.addr(), &length, &error);

  if(error)
    Glib::Error::throw_exception(error);

  return std::string(contents.get(), length);
}

void
file_set_contents(const std::string& filename,
                  const gchar *contents,
                  gssize length)
{
  GError* error  = nullptr;

  g_file_set_contents(filename.c_str(), contents, length, &error);

  if(error)
    Glib::Error::throw_exception(error);
}

void
file_set_contents (const std::string& filename, const std::string& contents)
{
    file_set_contents(filename, contents.c_str(), contents.size());
}

} // namespace Glib

namespace
{
} // anonymous namespace


Glib::FileError::FileError(Glib::FileError::Code error_code, const Glib::ustring& error_message)
:
  Glib::Error (G_FILE_ERROR, error_code, error_message)
{}

Glib::FileError::FileError(GError* gobject)
:
  Glib::Error (gobject)
{}

Glib::FileError::Code Glib::FileError::code() const
{
  return static_cast<Code>(Glib::Error::code());
}

void Glib::FileError::throw_func(GError* gobject)
{
  throw Glib::FileError(gobject);
}


