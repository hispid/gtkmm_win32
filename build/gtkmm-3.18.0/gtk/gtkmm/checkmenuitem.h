// -*- c++ -*-
// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!
#ifndef _GTKMM_CHECKMENUITEM_H
#define _GTKMM_CHECKMENUITEM_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <gtkmm/menuitem.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkCheckMenuItem GtkCheckMenuItem;
typedef struct _GtkCheckMenuItemClass GtkCheckMenuItemClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class CheckMenuItem_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A menu item that maintains the state of a boolean value in addition to a Gtk::MenuItem's usual role in activating application code.
 * A check box indicating the state of the boolean value is displayed at the left side of the Gtk::MenuItem.
 * Activating the Gtk::MenuItem toggles the value.
 * @ingroup Widgets
 * @ingroup Menus
 */

class CheckMenuItem : public MenuItem
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef CheckMenuItem CppObjectType;
  typedef CheckMenuItem_Class CppClassType;
  typedef GtkCheckMenuItem BaseObjectType;
  typedef GtkCheckMenuItemClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  CheckMenuItem(CheckMenuItem&& src) noexcept;
  CheckMenuItem& operator=(CheckMenuItem&& src) noexcept;

  // noncopyable
  CheckMenuItem(const CheckMenuItem&) = delete;
  CheckMenuItem& operator=(const CheckMenuItem&) = delete;

  virtual ~CheckMenuItem() noexcept;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class CheckMenuItem_Class;
  static CppClassType checkmenuitem_class_;

protected:
  explicit CheckMenuItem(const Glib::ConstructParams& construct_params);
  explicit CheckMenuItem(GtkCheckMenuItem* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkCheckMenuItem*       gobj()       { return reinterpret_cast<GtkCheckMenuItem*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkCheckMenuItem* gobj() const { return reinterpret_cast<GtkCheckMenuItem*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_toggled().
  virtual void on_toggled();


private:

public:

  CheckMenuItem();
  explicit CheckMenuItem(const Glib::ustring& label, bool mnemonic = false);


  /** Sets the active state of the menu item’s check box.
   * 
   * @param is_active Boolean value indicating whether the check box is active.
   */
  void set_active(bool is_active =  true);
  
  /** Returns whether the check menu item is active. See
   * set_active().
   * 
   * @return <tt>true</tt> if the menu item is checked.
   */
  bool get_active() const;

  
  /** Emits the Gtk::CheckMenuItem::signal_toggled() signal.
   */
  void toggled();

  
  /** If the user has selected a range of elements (such as some text or
   * spreadsheet cells) that are affected by a boolean setting, and the
   * current values in that range are inconsistent, you may want to
   * display the check in an “in between” state. This function turns on
   * “in between” display.  Normally you would turn off the inconsistent
   * state again if the user explicitly selects a setting. This has to be
   * done manually, set_inconsistent() only affects
   * visual appearance, it doesn’t affect the semantics of the widget.
   * 
   * @param setting <tt>true</tt> to display an “inconsistent” third state check.
   */
  void set_inconsistent(bool setting =  true);
  
  /** Retrieves the value set by set_inconsistent().
   * 
   * @return <tt>true</tt> if inconsistent.
   */
  bool get_inconsistent() const;

  
  /** Sets whether @a check_menu_item is drawn like a Gtk::RadioMenuItem
   * 
   * @newin{2,4}
   * 
   * @param draw_as_radio Whether @a check_menu_item is drawn like a Gtk::RadioMenuItem.
   */
  void set_draw_as_radio(bool draw_as_radio =  true);
  
  /** Returns whether @a check_menu_item looks like a Gtk::RadioMenuItem
   * 
   * @newin{2,4}
   * 
   * @return Whether @a check_menu_item looks like a Gtk::RadioMenuItem.
   */
  bool get_draw_as_radio() const;

  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%toggled()</tt>
   *
   * This signal is emitted when the state of the check box is changed.
   * 
   * A signal handler can use Gtk::CheckMenuItem::get_active()
   * to discover the new state.
   */

  Glib::SignalProxy0< void > signal_toggled();


  /** Whether the menu item is checked.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_active() ;

/** Whether the menu item is checked.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_active() const;

  /** Whether to display an 'inconsistent' state.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_inconsistent() ;

/** Whether to display an 'inconsistent' state.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_inconsistent() const;

  /** Whether the menu item looks like a radio menu item.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_draw_as_radio() ;

/** Whether the menu item looks like a radio menu item.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_draw_as_radio() const;


protected:


  /** Triggered when the item is redrawn (e.g.after being toggled)
   * Overload this signal if you want to implement your own check item
   * look. Otherwise, you most likely don't care about it.
   * The GdkRectangle specifies the area of the widget which will get
   * redrawn.
   */
    virtual void draw_indicator_vfunc(const ::Cairo::RefPtr< ::Cairo::Context>& cr);


};

} //namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::CheckMenuItem
   */
  Gtk::CheckMenuItem* wrap(GtkCheckMenuItem* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_CHECKMENUITEM_H */

