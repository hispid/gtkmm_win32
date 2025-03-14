// -*- c++ -*-
// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!
#ifndef _GTKMM_COLORSELECTION_P_H
#define _GTKMM_COLORSELECTION_P_H
#ifndef GTKMM_DISABLE_DEPRECATED


#include <gtkmm/private/hvbox_p.h>
#include <gtkmm/private/dialog_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class ColorSelection_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ColorSelection CppObjectType;
  typedef GtkColorSelection BaseObjectType;
  typedef GtkColorSelectionClass BaseClassType;
  typedef Gtk::VBox_Class CppClassParent;
  typedef GtkVBoxClass BaseClassParent;

  friend class ColorSelection;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void color_changed_callback(GtkColorSelection* self);

  //Callbacks (virtual functions):
};


} // namespace Gtk


#include <glibmm/class.h>

namespace Gtk
{

class ColorSelectionDialog_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ColorSelectionDialog CppObjectType;
  typedef GtkColorSelectionDialog BaseObjectType;
  typedef GtkColorSelectionDialogClass BaseClassType;
  typedef Gtk::Dialog_Class CppClassParent;
  typedef GtkDialogClass BaseClassParent;

  friend class ColorSelectionDialog;
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

#endif // GTKMM_DISABLE_DEPRECATED


#endif /* _GTKMM_COLORSELECTION_P_H */

