// -*- c++ -*-
// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!
#ifndef _GTKMM_PLACESSIDEBAR_P_H
#define _GTKMM_PLACESSIDEBAR_P_H


#include <gtkmm/private/scrolledwindow_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class PlacesSidebar_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef PlacesSidebar CppObjectType;
  typedef GtkPlacesSidebar BaseObjectType;
  typedef GtkPlacesSidebarClass BaseClassType;
  typedef Gtk::ScrolledWindow_Class CppClassParent;
  typedef GtkScrolledWindowClass BaseClassParent;

  friend class PlacesSidebar;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_PLACESSIDEBAR_P_H */

