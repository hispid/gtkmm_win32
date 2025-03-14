// -*- c++ -*-
// Generated by gmmproc 2.46.3 -- DO NOT MODIFY!
#ifndef _GIOMM_MENUATTRIBUTEITER_H
#define _GIOMM_MENUATTRIBUTEITER_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2012 The giomm Development Team
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

#include <glibmm/object.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GMenuAttributeIter GMenuAttributeIter;
typedef struct _GMenuAttributeIterClass GMenuAttributeIterClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class MenuAttributeIter_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** MenuAttributeIter - A menu attribute iterator.
 * @newin{2,32}
 */

class MenuAttributeIter : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef MenuAttributeIter CppObjectType;
  typedef MenuAttributeIter_Class CppClassType;
  typedef GMenuAttributeIter BaseObjectType;
  typedef GMenuAttributeIterClass BaseClassType;

  // noncopyable
  MenuAttributeIter(const MenuAttributeIter&) = delete;
  MenuAttributeIter& operator=(const MenuAttributeIter&) = delete;

private:  friend class MenuAttributeIter_Class;
  static CppClassType menuattributeiter_class_;

protected:
  explicit MenuAttributeIter(const Glib::ConstructParams& construct_params);
  explicit MenuAttributeIter(GMenuAttributeIter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  MenuAttributeIter(MenuAttributeIter&& src) noexcept;
  MenuAttributeIter& operator=(MenuAttributeIter&& src) noexcept;

  virtual ~MenuAttributeIter() noexcept;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GMenuAttributeIter*       gobj()       { return reinterpret_cast<GMenuAttributeIter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GMenuAttributeIter* gobj() const { return reinterpret_cast<GMenuAttributeIter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GMenuAttributeIter* gobj_copy();

private:


protected:
  MenuAttributeIter();

public:
  
  /** This function combines g_menu_attribute_iter_next() with
   * g_menu_attribute_iter_get_name() and g_menu_attribute_iter_get_value().
   * 
   * First the iterator is advanced to the next (possibly first) attribute.
   * If that fails, then <tt>false</tt> is returned and there are no other
   * effects.
   * 
   * If successful, @a name and @a value are set to the name and value of the
   * attribute that has just been advanced to.  At this point,
   * g_menu_attribute_iter_get_name() and g_menu_attribute_iter_get_value() will
   * return the same values again.
   * 
   * The value returned in @a name remains valid for as long as the iterator
   * remains at the current position.  The value returned in @a value must
   * be unreffed using Glib::variant_unref() when it is no longer in use.
   * 
   * @newin{2,32}
   * 
   * @param out_name The type of the attribute.
   * @param value The attribute value.
   * @return <tt>true</tt> on success, or <tt>false</tt> if there is no additional
   * attribute.
   */

  bool get_next(Glib::ustring& out_name, Glib::VariantBase& value);

  
  /** Gets the name of the attribute at the current iterator position, as
   * a string.
   * 
   * The iterator is not advanced.
   * 
   * @newin{2,32}
   * 
   * @return The name of the attribute.
   */
  Glib::ustring get_name() const;

  //TODO: When we can break ABI, remove the method overload and just make it const.
  //It makes no sense to return const by value.
  
  /** Gets the value of the attribute at the current iterator position.
   * 
   * The iterator is not advanced.
   * 
   * @newin{2,32}
   * 
   * @return The value of the current attribute.
   */
  Glib::VariantBase get_value();
  
  /** Gets the value of the attribute at the current iterator position.
   * 
   * The iterator is not advanced.
   * 
   * @newin{2,32}
   * 
   * @return The value of the current attribute.
   */
  const Glib::VariantBase get_value() const;

  
  /** Attempts to advance the iterator to the next (possibly first)
   * attribute.
   * 
   * <tt>true</tt> is returned on success, or <tt>false</tt> if there are no more
   * attributes.
   * 
   * You must call this function when you first acquire the iterator
   * to advance it to the first attribute (and determine if the first
   * attribute exists at all).
   * 
   * @newin{2,32}
   * 
   * @return <tt>true</tt> on success, or <tt>false</tt> when there are no more attributes.
   */
  bool next();


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::MenuAttributeIter
   */
  Glib::RefPtr<Gio::MenuAttributeIter> wrap(GMenuAttributeIter* object, bool take_copy = false);
}


#endif /* _GIOMM_MENUATTRIBUTEITER_H */

