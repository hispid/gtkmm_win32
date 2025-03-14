// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/applicationwindow.h>
#include <gtkmm/private/applicationwindow_p.h>


/* Copyright 2012 The gtkmm Development Team
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

#include <gtkmm/applicationwindow.h>

namespace Gtk
{


} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gtk::ApplicationWindow> wrap(GtkApplicationWindow* object, bool take_copy)
{
  return Glib::RefPtr<Gtk::ApplicationWindow>( dynamic_cast<Gtk::ApplicationWindow*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& ApplicationWindow_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ApplicationWindow_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_application_window_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Gio::ActionGroup::add_interface(get_type());
  Gio::ActionMap::add_interface(get_type());

  }

  return *this;
}


void ApplicationWindow_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* ApplicationWindow_Class::wrap_new(GObject* object)
{
  return new ApplicationWindow((GtkApplicationWindow*)object);
}


/* The implementation: */

GtkApplicationWindow* ApplicationWindow::gobj_copy()
{
  reference();
  return gobj();
}

ApplicationWindow::ApplicationWindow(const Glib::ConstructParams& construct_params)
:
  Gtk::Window(construct_params)
{

}

ApplicationWindow::ApplicationWindow(GtkApplicationWindow* castitem)
:
  Gtk::Window((GtkWindow*)(castitem))
{}


ApplicationWindow::ApplicationWindow(ApplicationWindow&& src) noexcept
: Gtk::Window(std::move(src))
  , Gio::ActionGroup(std::move(src))
  , Gio::ActionMap(std::move(src))
{}

ApplicationWindow& ApplicationWindow::operator=(ApplicationWindow&& src) noexcept
{
  Gtk::Window::operator=(std::move(src));
  Gio::ActionGroup::operator=(std::move(src));
  Gio::ActionMap::operator=(std::move(src));
  return *this;
}

ApplicationWindow::~ApplicationWindow() noexcept
{}


ApplicationWindow::CppClassType ApplicationWindow::applicationwindow_class_; // initialize static member

GType ApplicationWindow::get_type()
{
  return applicationwindow_class_.init().get_type();
}


GType ApplicationWindow::get_base_type()
{
  return gtk_application_window_get_type();
}


ApplicationWindow::ApplicationWindow()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Window(Glib::ConstructParams(applicationwindow_class_.init()))
{
  

}

ApplicationWindow::ApplicationWindow(const Glib::RefPtr<Application>& application)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Window(Glib::ConstructParams(applicationwindow_class_.init(), "application", Glib::unwrap(application), static_cast<char*>(0)))
{
  

}

void ApplicationWindow::set_show_menubar(bool show_menubar)
{
  gtk_application_window_set_show_menubar(gobj(), static_cast<int>(show_menubar));
}

bool ApplicationWindow::get_show_menubar() const
{
  return gtk_application_window_get_show_menubar(const_cast<GtkApplicationWindow*>(gobj()));
}

guint ApplicationWindow::get_id() const
{
  return gtk_application_window_get_id(const_cast<GtkApplicationWindow*>(gobj()));
}


Glib::PropertyProxy< bool > ApplicationWindow::property_show_menubar() 
{
  return Glib::PropertyProxy< bool >(this, "show-menubar");
}

Glib::PropertyProxy_ReadOnly< bool > ApplicationWindow::property_show_menubar() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "show-menubar");
}


} // namespace Gtk


