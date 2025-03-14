// -*- c++ -*-
// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!
#ifndef _GTKMM_APPCHOOSERBUTTON_P_H
#define _GTKMM_APPCHOOSERBUTTON_P_H


#include <gtkmm/private/combobox_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class AppChooserButton_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef AppChooserButton CppObjectType;
  typedef GtkAppChooserButton BaseObjectType;
  typedef GtkAppChooserButtonClass BaseClassType;
  typedef ComboBox_Class CppClassParent;
  typedef GtkComboBoxClass BaseClassParent;

  friend class AppChooserButton;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void custom_item_activated_callback(GtkAppChooserButton* self, const gchar* p0);

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_APPCHOOSERBUTTON_P_H */

