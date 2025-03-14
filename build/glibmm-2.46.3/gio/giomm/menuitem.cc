// Generated by gmmproc 2.46.3 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/menuitem.h>
#include <giomm/private/menuitem_p.h>


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

#include <gio/gio.h>

namespace Gio
{

MenuItem::MenuItem(const Glib::ustring& label, const Glib::ustring& detailed_action)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(menuitem_class_.init()))
{
  if(!label.empty())
    set_label(label);

  if(!detailed_action.empty())
    set_detailed_action(detailed_action);
}

MenuItem::MenuItem(const Glib::ustring& label, const Glib::RefPtr<MenuModel>& submenu)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(menuitem_class_.init()))
{
  if(!label.empty())
    set_label(label);

  set_submenu(submenu);
}

MenuItem::MenuItem(const Glib::RefPtr<MenuModel>& submenu)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(menuitem_class_.init()))
{
  set_submenu(submenu);
}

void MenuItem::set_action_and_target(const Glib::ustring& action)
{
  g_menu_item_set_action_and_target_value(gobj(), action.c_str(), 0);
}

void MenuItem::set_action(const Glib::ustring& action)
{
  g_menu_item_set_action_and_target_value(gobj(), action.c_str(), 0);
}

void MenuItem::unset_target()
{
  const gchar *action_name = nullptr;
  g_menu_item_get_attribute (gobj(), G_MENU_ATTRIBUTE_ACTION, "&s", &action_name);
 
  g_menu_item_set_action_and_target_value(gobj(), action_name, 0);
}

void MenuItem::unset_action_and_target()
{
  g_menu_item_set_action_and_target_value(gobj(), 0, 0);
}

void MenuItem::unset_icon()
{
  g_menu_item_set_icon(gobj(), 0);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gio::MenuItem> wrap(GMenuItem* object, bool take_copy)
{
  return Glib::RefPtr<Gio::MenuItem>( dynamic_cast<Gio::MenuItem*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

const Glib::Class& MenuItem_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &MenuItem_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_menu_item_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void MenuItem_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* MenuItem_Class::wrap_new(GObject* object)
{
  return new MenuItem((GMenuItem*)object);
}


/* The implementation: */

GMenuItem* MenuItem::gobj_copy()
{
  reference();
  return gobj();
}

MenuItem::MenuItem(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

MenuItem::MenuItem(GMenuItem* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


MenuItem::MenuItem(MenuItem&& src) noexcept
: Glib::Object(std::move(src))
{}

MenuItem& MenuItem::operator=(MenuItem&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  return *this;
}

MenuItem::~MenuItem() noexcept
{}


MenuItem::CppClassType MenuItem::menuitem_class_; // initialize static member

GType MenuItem::get_type()
{
  return menuitem_class_.init().get_type();
}


GType MenuItem::get_base_type()
{
  return g_menu_item_get_type();
}


Glib::RefPtr<MenuItem> MenuItem::create(const Glib::ustring& label, const Glib::ustring& detailed_action)
{
  return Glib::RefPtr<MenuItem>( new MenuItem(label, detailed_action) );
}

Glib::RefPtr<MenuItem> MenuItem::create(const Glib::ustring& label, const Glib::RefPtr<MenuModel>& submenu)
{
  return Glib::RefPtr<MenuItem>( new MenuItem(label, submenu) );
}

Glib::RefPtr<MenuItem> MenuItem::create(const Glib::RefPtr<MenuModel>& submenu)
{
  return Glib::RefPtr<MenuItem>( new MenuItem(submenu) );
}

void MenuItem::set_attribute_value(const Glib::ustring& attribute, const Glib::VariantBase& value)
{
  g_menu_item_set_attribute_value(gobj(), attribute.c_str(), const_cast<GVariant*>((value).gobj()));
}

#ifndef GIOMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
void MenuItem::set_attribute(const Glib::ustring& attribute, const Glib::VariantBase& value)
{
  g_menu_item_set_attribute_value(gobj(), attribute.c_str(), const_cast<GVariant*>((value).gobj()));
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GIOMM_DISABLE_DEPRECATED

Glib::RefPtr<MenuModel> MenuItem::get_link(const Glib::ustring& link)
{
  return Glib::wrap(g_menu_item_get_link(gobj(), link.c_str()));
}

Glib::RefPtr<const MenuModel> MenuItem::get_link(const Glib::ustring& link) const
{
  return const_cast<MenuItem*>(this)->get_link(link);
}

void MenuItem::set_link(const Glib::ustring& link, const Glib::RefPtr<MenuModel>& model)
{
  g_menu_item_set_link(gobj(), link.c_str(), const_cast<GMenuModel*>(Glib::unwrap(model)));
}

void MenuItem::set_label(const Glib::ustring& label)
{
  g_menu_item_set_label(gobj(), label.c_str());
}

void MenuItem::set_submenu(const Glib::RefPtr<MenuModel>& submenu)
{
  g_menu_item_set_submenu(gobj(), const_cast<GMenuModel*>(Glib::unwrap(submenu)));
}

void MenuItem::set_section(const Glib::RefPtr<MenuModel>& section)
{
  g_menu_item_set_section(gobj(), const_cast<GMenuModel*>(Glib::unwrap(section)));
}

#ifndef GIOMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
Glib::VariantBase MenuItem::get_attribute(const Glib::ustring& attribute, const Glib::VariantType& expected_type) const
{
  return Glib::wrap(g_menu_item_get_attribute_value(const_cast<GMenuItem*>(gobj()), attribute.c_str(), (expected_type).gobj()), false);
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GIOMM_DISABLE_DEPRECATED

#ifndef GIOMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
Glib::VariantBase MenuItem::get_attribute(const Glib::ustring& attribute) const
{
  return Glib::wrap(g_menu_item_get_attribute_value(const_cast<GMenuItem*>(gobj()), attribute.c_str(), 0), false);
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GIOMM_DISABLE_DEPRECATED

Glib::VariantBase MenuItem::get_attribute_value(const Glib::ustring& attribute, const Glib::VariantType& expected_type) const
{
  return Glib::wrap(g_menu_item_get_attribute_value(const_cast<GMenuItem*>(gobj()), attribute.c_str(), (expected_type).gobj()), false);
}

Glib::VariantBase MenuItem::get_attribute_value(const Glib::ustring& attribute) const
{
  return Glib::wrap(g_menu_item_get_attribute_value(const_cast<GMenuItem*>(gobj()), attribute.c_str(), 0), false);
}

void MenuItem::set_action_and_target(const Glib::ustring& action, const Glib::VariantBase& target_value)
{
  g_menu_item_set_action_and_target_value(gobj(), action.c_str(), const_cast<GVariant*>((target_value).gobj()));
}

void MenuItem::set_detailed_action(const Glib::ustring& detailed_action)
{
  g_menu_item_set_detailed_action(gobj(), detailed_action.c_str());
}

void MenuItem::set_icon(const Glib::RefPtr<Icon>& icon)
{
  g_menu_item_set_icon(gobj(), const_cast<GIcon*>(Glib::unwrap(icon)));
}


} // namespace Gio


