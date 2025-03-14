// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/window.h>
#include <gtkmm/private/window_p.h>


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

#include <glibmm/vectorutils.h>

#include <gtkmm/accelgroup.h>
#include <gdkmm/cursor.h>
#include <gtk/gtk.h>


namespace Gtk
{

Glib::RefPtr<AccelGroup> Window::get_accel_group()
{
  //There doesn't seem to be any gtk_window_get_accel_group().
  //I think that you're supposed to remember what you added yourself.
  //And that's what we do here.

  if(!accel_group_)
  {
    accel_group_ = AccelGroup::create();
    add_accel_group(accel_group_);
  }

  return accel_group_;
}

void Window::raise()
{
  get_window()->raise();
}

void Window::set_manage()
{
  g_warning("gtkmm: Attempt to call Gtk::manage() on a Gtk::Window, but a Gtk::Window has no parent container to manage its lifetime.\n");
}

void Window::destroy_()
{
  //Called from destructors.
  //overridden so that the correct _release_c_instance() ends up being called by the destructor.
  //destroy_() is virtual, but _release_c_instance() is not.

  //GTKMM_LIFECYCLE

  #ifdef GLIBMM_DEBUG_REFCOUNTING
  g_warning("Gtk::Window::destroy_(): gobject_: %p\n", (void*) gobject_);
  if(gobject_)
   g_warning("  gtypename: %s\n", G_OBJECT_TYPE_NAME(gobject_));
  #endif

  if ( !cpp_destruction_in_progress_ )
  {
    cpp_destruction_in_progress_ = true;

    //destroy the C instance:
    _release_c_instance();
  }

  //The C++ destructor will be reached later. This function was called by a destructor.
}

void Window::_release_c_instance()
{
  //We override this, (though it's not virtual - we just call it from this class),
  //because top-level windows can only be destroyed with gtk_widget_destroy, according to Owen Taylor. murrayc.
  #ifdef GLIBMM_DEBUG_REFCOUNTING
  g_warning("Gtk::Window::_release_c_instance() gobject_=%p\n", (void*) gobject_);
  #endif

  cpp_destruction_in_progress_ = true;

  // remove our hook.
  GtkWidget* object = GTK_WIDGET(gobj());
  if (object)
  {
    //We can't do anything with the gobject_ if it's already been disposed.
    //This prevents us from unref-ing it again, or destroying it again after GTK+ has told us that it has been disposed.
    if (!gobject_disposed_)
    {
      //Windows can not be unrefed. They are "self-owning".
      gtk_widget_destroy(object);
    }

    //If the GObject still exists, disconnect the C++ wrapper from it.
    //The C++ wrapper is being deleted right now.
    disconnect_cpp_wrapper();

    //Glib::Object::~Object() will not g_object_unref() it too, because gobject_ is now 0.
  }
}

void Window_Class::dispose_vfunc_callback(GObject* self)
{
  //Avoid disposal of Windows on delete_event (window close) signal.

  #ifdef GLIBMM_DEBUG_REFCOUNTING
  g_warning("Window_Class::dispose_vfunc_callback(): gobject_: %p\n", (void*)self);
  #endif

  const auto obj = dynamic_cast<Widget*>(
      Glib::ObjectBase::_get_current_wrapper(self));

  // This function might be invoked recursively because we're triggering
  // several signal emissions, particularly signal_hide().  Therefore we
  // have to test for cpp_destruction_in_progress_ at this point.

  if(obj && !obj->_cpp_destruction_is_in_progress()) //When it should really be destroyed, we zero gobj_.
  {
    const auto pWidget = obj->gobj();
    g_return_if_fail(pWidget == GTK_WIDGET(self));

    // Abort dispose if the widget isn't managed, in order to prevent
    // the nasty self-destroying behaviour of GTK+.  This applies to:
    //
    // - GtkWindow, if it received "delete_event"
    // - GtkDialog, which destroys on "response" by default

    #ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning("Window_Class::dispose_vfunc_callback(): before gtk_widget_hide().");
    #endif

    // Now hide the widget.  The C++ object must _not_ be accessed anymore
    // after this call, because a signal_hide() handler might delete it.
    gtk_widget_hide(pWidget);

    #ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning("Window_Class::dispose_vfunc_callback(): after gtk_widget_hide().");
    #endif

    // GTKMM_LIFECYCLE
    return; // Prevent calling of normal C dispose vfunc (see below)
  }
  else
  {
    #ifdef GLIBMM_DEBUG_REFCOUNTING
    //g_warning("Window_Class::dispose_vfunc_callback(): unreferenced: before gtk_widget_hide().");
    #endif

    // Always hide widgets on object destruction, regardless of whether
    // the widget is managed or not.  This is done for consistency so that
    // connecting to signal_hide() is guaranteed to work.
    //gtk_widget_hide(pWidget);

    #ifdef GLIBMM_DEBUG_REFCOUNTING
    //g_warning("Window_Class::dispose_vfunc_callback(): unreferenced:  after gtk_widget_hide().");
    #endif

    const auto base = static_cast<GObjectClass*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)));

    #ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning("Window_Class::dispose_vfunc_callback(): before calling base->dispose.");
    #endif

    if(base->dispose)
      (*base->dispose)(self);

    #ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning("Window_Class::dispose_vfunc_callback(): after calling base->dispose.");
    #endif
  }
}

void Window::unset_focus()
{
  gtk_window_set_focus(gobj(), 0 /* See GTK+ docs */);
}

void Window::unset_default()
{
  gtk_window_set_default(gobj(), 0 /* See GTK+ docs */);
}

void Window::unset_transient_for()
{
  gtk_window_set_transient_for(gobj(), 0 /* See GTK+ docs */);
}

void Window::unset_attached_to()
{
  gtk_window_set_attached_to(gobj(), 0 /* See GTK+ docs */);
}

void Window::unset_application()
{
  gtk_window_set_application(gobj(), 0 /* See GTK+ docs */);
}

#ifndef GTKMM_DISABLE_DEPRECATED
#ifdef GLIBMM_PROPERTIES_ENABLED
// This works. The base class GtkWidget contains the opacity property.
Glib::PropertyProxy< double > Window::property_opacity() 
{
  return Glib::PropertyProxy< double >(this, "opacity");
}

Glib::PropertyProxy_ReadOnly< double > Window::property_opacity() const
{
  return Glib::PropertyProxy_ReadOnly< double >(this, "opacity");
}
#endif //GLIBMM_PROPERTIES_ENABLED
#endif // GTKMM_DISABLE_DEPRECATED

} // namespace Gtk

namespace
{


static void Window_signal_set_focus_callback(GtkWindow* self, GtkWidget* p0,void* data)
{
  using namespace Gtk;
  typedef sigc::slot< void,Widget* > SlotType;

  auto obj = dynamic_cast<Window*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

static const Glib::SignalProxyInfo Window_signal_set_focus_info =
{
  "set_focus",
  (GCallback) &Window_signal_set_focus_callback,
  (GCallback) &Window_signal_set_focus_callback
};


static const Glib::SignalProxyInfo Window_signal_keys_changed_info =
{
  "keys_changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

Gtk::Window* wrap(GtkWindow* object, bool take_copy)
{
  return dynamic_cast<Gtk::Window *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& Window_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Window_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_window_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void Window_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

    reinterpret_cast<GObjectClass*>(klass)->dispose = &dispose_vfunc_callback;
  
  klass->set_focus = &set_focus_callback;
}


void Window_Class::set_focus_callback(GtkWindow* self, GtkWidget* p0)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_set_focus(Glib::wrap(p0)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->set_focus)
    (*base->set_focus)(self, p0);
}


Glib::ObjectBase* Window_Class::wrap_new(GObject* o)
{
  return new Window((GtkWindow*)(o)); //top-level windows can not be manage()ed.

}


/* The implementation: */

Window::Window(const Glib::ConstructParams& construct_params)
:
  Gtk::Bin(construct_params)
{
  }

Window::Window(GtkWindow* castitem)
:
  Gtk::Bin((GtkBin*)(castitem))
{
  }


Window::Window(Window&& src) noexcept
: Gtk::Bin(std::move(src))
{}

Window& Window::operator=(Window&& src) noexcept
{
  Gtk::Bin::operator=(std::move(src));
  return *this;
}

Window::~Window() noexcept
{
  destroy_();
}

Window::CppClassType Window::window_class_; // initialize static member

GType Window::get_type()
{
  return window_class_.init().get_type();
}


GType Window::get_base_type()
{
  return gtk_window_get_type();
}


Window::Window(WindowType type)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Bin(Glib::ConstructParams(window_class_.init(), "type", ((GtkWindowType)(type)), static_cast<char*>(0)))
{
  

}

void Window::set_title(const Glib::ustring& title)
{
  gtk_window_set_title(gobj(), title.c_str());
}

Glib::ustring Window::get_title() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_window_get_title(const_cast<GtkWindow*>(gobj())));
}

void Window::set_wmclass(const Glib::ustring& wmclass_name, const Glib::ustring& wmclass_class)
{
  gtk_window_set_wmclass(gobj(), wmclass_name.c_str(), wmclass_class.c_str());
}

void Window::set_role(const Glib::ustring& role)
{
  gtk_window_set_role(gobj(), role.c_str());
}

void Window::set_startup_id(const Glib::ustring& startup_id)
{
  gtk_window_set_startup_id(gobj(), startup_id.c_str());
}

Glib::ustring Window::get_role() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_window_get_role(const_cast<GtkWindow*>(gobj())));
}

void Window::add_accel_group(const Glib::RefPtr<AccelGroup>& accel_group)
{
  gtk_window_add_accel_group(gobj(), Glib::unwrap(accel_group));
}

void Window::remove_accel_group(const Glib::RefPtr<AccelGroup>& accel_group)
{
  gtk_window_remove_accel_group(gobj(), Glib::unwrap(accel_group));
}

void Window::set_position(WindowPosition position)
{
  gtk_window_set_position(gobj(), ((GtkWindowPosition)(position)));
}

bool Window::activate_focus()
{
  return gtk_window_activate_focus(gobj());
}

void Window::set_focus(Gtk::Widget& focus)
{
  gtk_window_set_focus(gobj(), (focus).gobj());
}

Widget* Window::get_focus()
{
  return Glib::wrap(gtk_window_get_focus(gobj()));
}

const Widget* Window::get_focus() const
{
  return const_cast<Window*>(this)->get_focus();
}

void Window::set_default(Gtk::Widget& default_widget)
{
  gtk_window_set_default(gobj(), (default_widget).gobj());
}

Widget* Window::get_default_widget()
{
  return Glib::wrap(gtk_window_get_default_widget(gobj()));
}

const Widget* Window::get_default_widget() const
{
  return const_cast<Window*>(this)->get_default_widget();
}

bool Window::activate_default()
{
  return gtk_window_activate_default(gobj());
}

void Window::set_transient_for(Window& parent)
{
  gtk_window_set_transient_for(gobj(), (parent).gobj());
}

Window* Window::get_transient_for()
{
  return Glib::wrap(gtk_window_get_transient_for(gobj()));
}

const Window* Window::get_transient_for() const
{
  return const_cast<Window*>(this)->get_transient_for();
}

void Window::set_attached_to(Widget& attach_widget)
{
  gtk_window_set_attached_to(gobj(), (attach_widget).gobj());
}

Widget* Window::get_attached_to()
{
  return Glib::wrap(gtk_window_get_attached_to(gobj()));
}

const Widget* Window::get_attached_to() const
{
  return const_cast<Window*>(this)->get_attached_to();
}

#ifndef GTKMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
void Window::set_opacity(double opacity)
{
  gtk_window_set_opacity(gobj(), opacity);
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GTKMM_DISABLE_DEPRECATED

#ifndef GTKMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
double Window::get_opacity() const
{
  return gtk_window_get_opacity(const_cast<GtkWindow*>(gobj()));
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GTKMM_DISABLE_DEPRECATED

void Window::set_type_hint(Gdk::WindowTypeHint hint)
{
  gtk_window_set_type_hint(gobj(), ((GdkWindowTypeHint)(hint)));
}

Gdk::WindowTypeHint Window::get_type_hint() const
{
  return ((Gdk::WindowTypeHint)(gtk_window_get_type_hint(const_cast<GtkWindow*>(gobj()))));
}

void Window::set_skip_taskbar_hint(bool setting)
{
  gtk_window_set_skip_taskbar_hint(gobj(), static_cast<int>(setting));
}

bool Window::get_skip_taskbar_hint() const
{
  return gtk_window_get_skip_taskbar_hint(const_cast<GtkWindow*>(gobj()));
}

void Window::set_skip_pager_hint(bool setting)
{
  gtk_window_set_skip_pager_hint(gobj(), static_cast<int>(setting));
}

bool Window::get_skip_pager_hint() const
{
  return gtk_window_get_skip_pager_hint(const_cast<GtkWindow*>(gobj()));
}

void Window::set_urgency_hint(bool setting)
{
  gtk_window_set_urgency_hint(gobj(), static_cast<int>(setting));
}

bool Window::get_urgency_hint() const
{
  return gtk_window_get_urgency_hint(const_cast<GtkWindow*>(gobj()));
}

void Window::set_accept_focus(bool setting)
{
  gtk_window_set_accept_focus(gobj(), static_cast<int>(setting));
}

bool Window::get_accept_focus() const
{
  return gtk_window_get_accept_focus(const_cast<GtkWindow*>(gobj()));
}

void Window::set_focus_on_map(bool setting)
{
  gtk_window_set_focus_on_map(gobj(), static_cast<int>(setting));
}

bool Window::get_focus_on_map() const
{
  return gtk_window_get_focus_on_map(const_cast<GtkWindow*>(gobj()));
}

bool Window::get_destroy_with_parent() const
{
  return gtk_window_get_destroy_with_parent(const_cast<GtkWindow*>(gobj()));
}

void Window::set_hide_titlebar_when_maximized(bool setting)
{
  gtk_window_set_hide_titlebar_when_maximized(gobj(), static_cast<int>(setting));
}

bool Window::get_hide_titlebar_when_maximized() const
{
  return gtk_window_get_hide_titlebar_when_maximized(const_cast<GtkWindow*>(gobj()));
}

void Window::set_mnemonics_visible(bool setting)
{
  gtk_window_set_mnemonics_visible(gobj(), static_cast<int>(setting));
}

bool Window::get_mnemonics_visible() const
{
  return gtk_window_get_mnemonics_visible(const_cast<GtkWindow*>(gobj()));
}

void Window::set_focus_visible(bool setting)
{
  gtk_window_set_focus_visible(gobj(), static_cast<int>(setting));
}

bool Window::get_focus_visible() const
{
  return gtk_window_get_focus_visible(const_cast<GtkWindow*>(gobj()));
}

void Window::set_resizable(bool resizable)
{
  gtk_window_set_resizable(gobj(), static_cast<int>(resizable));
}

bool Window::get_resizable() const
{
  return gtk_window_get_resizable(const_cast<GtkWindow*>(gobj()));
}

void Window::set_gravity(Gdk::Gravity gravity)
{
  gtk_window_set_gravity(gobj(), ((GdkGravity)(gravity)));
}

Gdk::Gravity Window::get_gravity() const
{
  return ((Gdk::Gravity)(gtk_window_get_gravity(const_cast<GtkWindow*>(gobj()))));
}

void Window::set_geometry_hints(Widget& geometry_widget, const Gdk::Geometry& geometry, Gdk::WindowHints geom_mask)
{
  gtk_window_set_geometry_hints(gobj(), (geometry_widget).gobj(), const_cast<GdkGeometry*>(&(geometry)), ((GdkWindowHints)(geom_mask)));
}

void Window::set_screen(const Glib::RefPtr<Gdk::Screen>& screen)
{
  gtk_window_set_screen(gobj(), Glib::unwrap(screen));
}

Glib::RefPtr<Gdk::Screen> Window::get_screen()
{
  Glib::RefPtr<Gdk::Screen> retvalue = Glib::wrap(gtk_window_get_screen(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Gdk::Screen> Window::get_screen() const
{
  return const_cast<Window*>(this)->get_screen();
}

bool Window::is_active() const
{
  return gtk_window_is_active(const_cast<GtkWindow*>(gobj()));
}

bool Window::has_toplevel_focus() const
{
  return gtk_window_has_toplevel_focus(const_cast<GtkWindow*>(gobj()));
}

void Window::set_decorated(bool setting)
{
  gtk_window_set_decorated(gobj(), static_cast<int>(setting));
}

bool Window::get_decorated() const
{
  return gtk_window_get_decorated(const_cast<GtkWindow*>(gobj()));
}

void Window::set_deletable(bool setting)
{
  gtk_window_set_deletable(gobj(), static_cast<int>(setting));
}

bool Window::get_deletable() const
{
  return gtk_window_get_deletable(const_cast<GtkWindow*>(gobj()));
}

std::vector< Glib::RefPtr<Gdk::Pixbuf> > Window::get_icon_list()
{
  return Glib::ListHandler< Glib::RefPtr<Gdk::Pixbuf> >::list_to_vector(gtk_window_get_icon_list(gobj()), Glib::OWNERSHIP_SHALLOW);
}

std::vector< Glib::RefPtr<const Gdk::Pixbuf> > Window::get_icon_list() const
{
  return Glib::ListHandler< Glib::RefPtr<const Gdk::Pixbuf> >::list_to_vector(gtk_window_get_icon_list(const_cast<GtkWindow*>(gobj())), Glib::OWNERSHIP_SHALLOW);
}

void Window::set_icon_list(const std::vector< Glib::RefPtr<Gdk::Pixbuf> >& list)
{
  gtk_window_set_icon_list(gobj(), Glib::ListHandler< Glib::RefPtr<Gdk::Pixbuf> >::vector_to_list(list).data ());
}

void Window::set_icon(const Glib::RefPtr<Gdk::Pixbuf>& icon)
{
  gtk_window_set_icon(gobj(), Glib::unwrap(icon));
}

void Window::set_icon_name(const Glib::ustring& name)
{
  gtk_window_set_icon_name(gobj(), name.c_str());
}

bool Window::set_icon_from_file(const std::string& filename)
{
  GError* gerror = nullptr;
  bool retvalue = gtk_window_set_icon_from_file(gobj(), filename.c_str(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

Glib::RefPtr<Gdk::Pixbuf> Window::get_icon()
{
  Glib::RefPtr<Gdk::Pixbuf> retvalue = Glib::wrap(gtk_window_get_icon(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Gdk::Pixbuf> Window::get_icon() const
{
  return const_cast<Window*>(this)->get_icon();
}

Glib::ustring Window::get_icon_name() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_window_get_icon_name(const_cast<GtkWindow*>(gobj())));
}

void Window::set_default_icon_list(const std::vector< Glib::RefPtr<Gdk::Pixbuf> >& list)
{
  gtk_window_set_default_icon_list(Glib::ListHandler< Glib::RefPtr<Gdk::Pixbuf> >::vector_to_list(list).data ());
}

std::vector< Glib::RefPtr<Gdk::Pixbuf> > Window::get_default_icon_list()
{
  return Glib::ListHandler< Glib::RefPtr<Gdk::Pixbuf> >::list_to_vector(gtk_window_get_default_icon_list(), Glib::OWNERSHIP_SHALLOW);
}

void Window::set_default_icon(const Glib::RefPtr<Gdk::Pixbuf>& icon)
{
  gtk_window_set_default_icon(Glib::unwrap(icon));
}

void Window::set_default_icon_name(const Glib::ustring& name)
{
  gtk_window_set_default_icon_name(name.c_str());
}

bool Window::set_default_icon_from_file(const std::string& filename)
{
  GError* gerror = nullptr;
  bool retvalue = gtk_window_set_default_icon_from_file(filename.c_str(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

void Window::set_auto_startup_notification(bool setting)
{
  gtk_window_set_auto_startup_notification(static_cast<int>(setting));
}

void Window::set_modal(bool modal)
{
  gtk_window_set_modal(gobj(), static_cast<int>(modal));
}

bool Window::get_modal() const
{
  return gtk_window_get_modal(const_cast<GtkWindow*>(gobj()));
}

std::vector<Window*> Window::list_toplevels()
{
  return Glib::ListHandler<Window*>::list_to_vector(gtk_window_list_toplevels(), Glib::OWNERSHIP_SHALLOW);
}

void Window::add_mnemonic(guint keyval, Widget& target)
{
  gtk_window_add_mnemonic(gobj(), keyval, (target).gobj());
}

void Window::remove_mnemonic(guint keyval, Widget& target)
{
  gtk_window_remove_mnemonic(gobj(), keyval, (target).gobj());
}

bool Window::mnemonic_activate(guint keyval, Gdk::ModifierType modifier)
{
  return gtk_window_mnemonic_activate(gobj(), keyval, ((GdkModifierType)(modifier)));
}

void Window::set_mnemonic_modifier(Gdk::ModifierType modifier)
{
  gtk_window_set_mnemonic_modifier(gobj(), ((GdkModifierType)(modifier)));
}

Gdk::ModifierType Window::get_mnemonic_modifier()
{
  return ((Gdk::ModifierType)(gtk_window_get_mnemonic_modifier(gobj())));
}

void Window::present()
{
  gtk_window_present(gobj());
}

void Window::present(guint32 timestamp)
{
  gtk_window_present_with_time(gobj(), timestamp);
}

void Window::iconify()
{
  gtk_window_iconify(gobj());
}

void Window::deiconify()
{
  gtk_window_deiconify(gobj());
}

void Window::stick()
{
  gtk_window_stick(gobj());
}

void Window::unstick()
{
  gtk_window_unstick(gobj());
}

void Window::maximize()
{
  gtk_window_maximize(gobj());
}

void Window::unmaximize()
{
  gtk_window_unmaximize(gobj());
}

void Window::fullscreen()
{
  gtk_window_fullscreen(gobj());
}

void Window::unfullscreen()
{
  gtk_window_unfullscreen(gobj());
}

void Window::fullscreen_on_monitor(const Glib::RefPtr<Gdk::Screen>& screen, int monitor)
{
  gtk_window_fullscreen_on_monitor(gobj(), Glib::unwrap(screen), monitor);
}

void Window::close()
{
  gtk_window_close(gobj());
}

void Window::begin_resize_drag(Gdk::WindowEdge edge, int button, int root_x, int root_y, guint32 timestamp)
{
  gtk_window_begin_resize_drag(gobj(), ((GdkWindowEdge)(edge)), button, root_x, root_y, timestamp);
}

void Window::begin_move_drag(int button, int root_x, int root_y, guint32 timestamp)
{
  gtk_window_begin_move_drag(gobj(), button, root_x, root_y, timestamp);
}

void Window::set_default_size(int width, int height)
{
  gtk_window_set_default_size(gobj(), width, height);
}

void Window::get_default_size(int& width, int& height) const
{
  gtk_window_get_default_size(const_cast<GtkWindow*>(gobj()), &(width), &(height));
}

void Window::resize(int width, int height)
{
  gtk_window_resize(gobj(), width, height);
}

void Window::get_size(int& width, int& height) const
{
  gtk_window_get_size(const_cast<GtkWindow*>(gobj()), &(width), &(height));
}

void Window::move(int x, int y)
{
  gtk_window_move(gobj(), x, y);
}

void Window::get_position(int& root_x, int& root_y) const
{
  gtk_window_get_position(const_cast<GtkWindow*>(gobj()), &(root_x), &(root_y));
}

bool Window::parse_geometry(const Glib::ustring& geometry)
{
  return gtk_window_parse_geometry(gobj(), geometry.c_str());
}

void Window::set_default_geometry(int width, int height)
{
  gtk_window_set_default_geometry(gobj(), width, height);
}

void Window::resize_to_geometry(int width, int height)
{
  gtk_window_resize_to_geometry(gobj(), width, height);
}

Glib::RefPtr<WindowGroup> Window::get_group()
{
  Glib::RefPtr<WindowGroup> retvalue = Glib::wrap(gtk_window_get_group(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const WindowGroup> Window::get_group() const
{
  return const_cast<Window*>(this)->get_group();
}

bool Window::has_group() const
{
  return gtk_window_has_group(const_cast<GtkWindow*>(gobj()));
}

WindowType Window::get_window_type() const
{
  return ((WindowType)(gtk_window_get_window_type(const_cast<GtkWindow*>(gobj()))));
}

#ifndef GTKMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
void Window::reshow_with_initial_size()
{
  gtk_window_reshow_with_initial_size(gobj());
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GTKMM_DISABLE_DEPRECATED

Glib::RefPtr<Application> Window::get_application()
{
  Glib::RefPtr<Application> retvalue = Glib::wrap(gtk_window_get_application(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Application> Window::get_application() const
{
  Glib::RefPtr<const Application> retvalue = Glib::wrap(gtk_window_get_application(const_cast<GtkWindow*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

void Window::set_application(const Glib::RefPtr<Application>& application)
{
  gtk_window_set_application(gobj(), Glib::unwrap(application));
}

#ifndef GTKMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
void Window::set_has_resize_grip(bool value)
{
  gtk_window_set_has_resize_grip(gobj(), static_cast<int>(value));
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GTKMM_DISABLE_DEPRECATED

#ifndef GTKMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
bool Window::get_has_resize_grip() const
{
  return gtk_window_get_has_resize_grip(const_cast<GtkWindow*>(gobj()));
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GTKMM_DISABLE_DEPRECATED

#ifndef GTKMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
bool Window::get_resize_grip_is_visible() const
{
  return gtk_window_resize_grip_is_visible(const_cast<GtkWindow*>(gobj()));
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GTKMM_DISABLE_DEPRECATED

#ifndef GTKMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
bool Window::get_resize_grip_area(Gdk::Rectangle& rect) const
{
  return gtk_window_get_resize_grip_area(const_cast<GtkWindow*>(gobj()), (rect).gobj());
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GTKMM_DISABLE_DEPRECATED

void Window::set_keep_above(bool setting)
{
  gtk_window_set_keep_above(gobj(), static_cast<int>(setting));
}

void Window::set_keep_below(bool setting)
{
  gtk_window_set_keep_below(gobj(), static_cast<int>(setting));
}

void Window::set_titlebar(Widget& titlebar)
{
  gtk_window_set_titlebar(gobj(), (titlebar).gobj());
}

Widget* Window::get_titlebar()
{
  return Glib::wrap(gtk_window_get_titlebar(gobj()));
}

const Widget* Window::get_titlebar() const
{
  return const_cast<Window*>(this)->get_titlebar();
}

bool Window::is_maximized() const
{
  return gtk_window_is_maximized(const_cast<GtkWindow*>(gobj()));
}


Glib::SignalProxy1< void,Widget* > Window::signal_set_focus()
{
  return Glib::SignalProxy1< void,Widget* >(this, &Window_signal_set_focus_info);
}


Glib::SignalProxy0< void > Window::signal_keys_changed()
{
  return Glib::SignalProxy0< void >(this, &Window_signal_keys_changed_info);
}


Glib::PropertyProxy_ReadOnly< WindowType > Window::property_type() const
{
  return Glib::PropertyProxy_ReadOnly< WindowType >(this, "type");
}

Glib::PropertyProxy< Glib::ustring > Window::property_title() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "title");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > Window::property_title() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "title");
}

Glib::PropertyProxy_WriteOnly< Glib::ustring > Window::property_startup_id() 
{
  return Glib::PropertyProxy_WriteOnly< Glib::ustring >(this, "startup-id");
}

Glib::PropertyProxy< bool > Window::property_resizable() 
{
  return Glib::PropertyProxy< bool >(this, "resizable");
}

Glib::PropertyProxy_ReadOnly< bool > Window::property_resizable() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "resizable");
}

Glib::PropertyProxy< bool > Window::property_modal() 
{
  return Glib::PropertyProxy< bool >(this, "modal");
}

Glib::PropertyProxy_ReadOnly< bool > Window::property_modal() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "modal");
}

Glib::PropertyProxy< WindowPosition > Window::property_window_position() 
{
  return Glib::PropertyProxy< WindowPosition >(this, "window-position");
}

Glib::PropertyProxy_ReadOnly< WindowPosition > Window::property_window_position() const
{
  return Glib::PropertyProxy_ReadOnly< WindowPosition >(this, "window-position");
}

Glib::PropertyProxy< int > Window::property_default_width() 
{
  return Glib::PropertyProxy< int >(this, "default-width");
}

Glib::PropertyProxy_ReadOnly< int > Window::property_default_width() const
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "default-width");
}

Glib::PropertyProxy< int > Window::property_default_height() 
{
  return Glib::PropertyProxy< int >(this, "default-height");
}

Glib::PropertyProxy_ReadOnly< int > Window::property_default_height() const
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "default-height");
}

Glib::PropertyProxy< bool > Window::property_destroy_with_parent() 
{
  return Glib::PropertyProxy< bool >(this, "destroy-with-parent");
}

Glib::PropertyProxy_ReadOnly< bool > Window::property_destroy_with_parent() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "destroy-with-parent");
}

Glib::PropertyProxy< bool > Window::property_hide_titlebar_when_maximized() 
{
  return Glib::PropertyProxy< bool >(this, "hide-titlebar-when-maximized");
}

Glib::PropertyProxy_ReadOnly< bool > Window::property_hide_titlebar_when_maximized() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "hide-titlebar-when-maximized");
}

Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixbuf> > Window::property_icon() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixbuf> >(this, "icon");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixbuf> > Window::property_icon() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixbuf> >(this, "icon");
}

Glib::PropertyProxy< bool > Window::property_mnemonics_visible() 
{
  return Glib::PropertyProxy< bool >(this, "mnemonics-visible");
}

Glib::PropertyProxy_ReadOnly< bool > Window::property_mnemonics_visible() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "mnemonics-visible");
}

Glib::PropertyProxy< Glib::ustring > Window::property_icon_name() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "icon-name");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > Window::property_icon_name() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "icon-name");
}

Glib::PropertyProxy< Glib::RefPtr<Gdk::Screen> > Window::property_screen() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Gdk::Screen> >(this, "screen");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Screen> > Window::property_screen() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Screen> >(this, "screen");
}

Glib::PropertyProxy_ReadOnly< bool > Window::property_is_active() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "is-active");
}

Glib::PropertyProxy_ReadOnly< bool > Window::property_has_toplevel_focus() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "has-toplevel-focus");
}

Glib::PropertyProxy< GdkWindowTypeHint > Window::property_type_hint() 
{
  return Glib::PropertyProxy< GdkWindowTypeHint >(this, "type-hint");
}

Glib::PropertyProxy_ReadOnly< GdkWindowTypeHint > Window::property_type_hint() const
{
  return Glib::PropertyProxy_ReadOnly< GdkWindowTypeHint >(this, "type-hint");
}

Glib::PropertyProxy< bool > Window::property_skip_taskbar_hint() 
{
  return Glib::PropertyProxy< bool >(this, "skip-taskbar-hint");
}

Glib::PropertyProxy_ReadOnly< bool > Window::property_skip_taskbar_hint() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "skip-taskbar-hint");
}

Glib::PropertyProxy< bool > Window::property_skip_pager_hint() 
{
  return Glib::PropertyProxy< bool >(this, "skip-pager-hint");
}

Glib::PropertyProxy_ReadOnly< bool > Window::property_skip_pager_hint() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "skip-pager-hint");
}

Glib::PropertyProxy< Glib::ustring > Window::property_role() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "role");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > Window::property_role() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "role");
}

Glib::PropertyProxy< bool > Window::property_decorated() 
{
  return Glib::PropertyProxy< bool >(this, "decorated");
}

Glib::PropertyProxy_ReadOnly< bool > Window::property_decorated() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "decorated");
}

Glib::PropertyProxy< Gdk::Gravity > Window::property_gravity() 
{
  return Glib::PropertyProxy< Gdk::Gravity >(this, "gravity");
}

Glib::PropertyProxy_ReadOnly< Gdk::Gravity > Window::property_gravity() const
{
  return Glib::PropertyProxy_ReadOnly< Gdk::Gravity >(this, "gravity");
}

Glib::PropertyProxy< Window* > Window::property_transient_for() 
{
  return Glib::PropertyProxy< Window* >(this, "transient-for");
}

Glib::PropertyProxy_ReadOnly< Window* > Window::property_transient_for() const
{
  return Glib::PropertyProxy_ReadOnly< Window* >(this, "transient-for");
}

#ifndef GTKMM_DISABLE_DEPRECATED

Glib::PropertyProxy< bool > Window::property_has_resize_grip() 
{
  return Glib::PropertyProxy< bool >(this, "has-resize-grip");
}
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

Glib::PropertyProxy_ReadOnly< bool > Window::property_has_resize_grip() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "has-resize-grip");
}
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

Glib::PropertyProxy_ReadOnly< bool > Window::property_resize_grip_visible() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "resize-grip-visible");
}
#endif // GTKMM_DISABLE_DEPRECATED


Glib::PropertyProxy< bool > Window::property_urgency_hint() 
{
  return Glib::PropertyProxy< bool >(this, "urgency-hint");
}

Glib::PropertyProxy_ReadOnly< bool > Window::property_urgency_hint() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "urgency-hint");
}

Glib::PropertyProxy< bool > Window::property_accept_focus() 
{
  return Glib::PropertyProxy< bool >(this, "accept-focus");
}

Glib::PropertyProxy_ReadOnly< bool > Window::property_accept_focus() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "accept-focus");
}

Glib::PropertyProxy< bool > Window::property_focus_on_map() 
{
  return Glib::PropertyProxy< bool >(this, "focus-on-map");
}

Glib::PropertyProxy_ReadOnly< bool > Window::property_focus_on_map() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "focus-on-map");
}

Glib::PropertyProxy< bool > Window::property_deletable() 
{
  return Glib::PropertyProxy< bool >(this, "deletable");
}

Glib::PropertyProxy_ReadOnly< bool > Window::property_deletable() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "deletable");
}

Glib::PropertyProxy< Glib::RefPtr<Application> > Window::property_application() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Application> >(this, "application");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Application> > Window::property_application() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Application> >(this, "application");
}

Glib::PropertyProxy< bool > Window::property_focus_visible() 
{
  return Glib::PropertyProxy< bool >(this, "focus-visible");
}

Glib::PropertyProxy_ReadOnly< bool > Window::property_focus_visible() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "focus-visible");
}

Glib::PropertyProxy< Widget* > Window::property_attached_to() 
{
  return Glib::PropertyProxy< Widget* >(this, "attached-to");
}

Glib::PropertyProxy_ReadOnly< Widget* > Window::property_attached_to() const
{
  return Glib::PropertyProxy_ReadOnly< Widget* >(this, "attached-to");
}

Glib::PropertyProxy_ReadOnly< bool > Window::property_is_maximized() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "is-maximized");
}


void Gtk::Window::on_set_focus(Widget* focus)
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->set_focus)
    (*base->set_focus)(gobj(),(GtkWidget*)Glib::unwrap(focus));
}


} // namespace Gtk


