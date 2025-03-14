// -*- c++ -*-
// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!
#ifndef _GTKMM_TOGGLEBUTTON_H
#define _GTKMM_TOGGLEBUTTON_H


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

#include <gtkmm/button.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkToggleButton GtkToggleButton;
typedef struct _GtkToggleButtonClass GtkToggleButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class ToggleButton_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A Gtk::ToggleButton will remain 'pressed-in' when clicked. Clicking again will cause the toggle button to return to it's normal state.
 * The state of a Gtk::ToggleButton can be set specifically using set_active(), and retrieved using get_active().
 * To simply switch the state of a toggle button, use toggled().
 *
 * @ingroup Widgets
 */

class ToggleButton : public Button
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ToggleButton CppObjectType;
  typedef ToggleButton_Class CppClassType;
  typedef GtkToggleButton BaseObjectType;
  typedef GtkToggleButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ToggleButton(ToggleButton&& src) noexcept;
  ToggleButton& operator=(ToggleButton&& src) noexcept;

  // noncopyable
  ToggleButton(const ToggleButton&) = delete;
  ToggleButton& operator=(const ToggleButton&) = delete;

  virtual ~ToggleButton() noexcept;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class ToggleButton_Class;
  static CppClassType togglebutton_class_;

protected:
  explicit ToggleButton(const Glib::ConstructParams& construct_params);
  explicit ToggleButton(GtkToggleButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkToggleButton*       gobj()       { return reinterpret_cast<GtkToggleButton*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkToggleButton* gobj() const { return reinterpret_cast<GtkToggleButton*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_toggled().
  virtual void on_toggled();


private:

public:

  /** Create an empty toggle button.
   * With an empty button, you can Gtk::Button::add() a widget such as a
   * Gtk::Image or Gtk::Box.
   *
   * If you just wish to add a Gtk::Label, you may want to use the
   * Gtk::ToggleButton(const Glib::ustring &label) constructor directly
   * instead.
   */
  ToggleButton();

  /** Create a toggle button with a label.
   * You won't be able
   * to add a widget to this button since it already contains a Gtk::Label
   */
  explicit ToggleButton(const Glib::ustring& label, bool mnemonic = false);

#ifndef GTKMM_DISABLE_DEPRECATED
  /** Creates a toggle button containing the image and text from a stock item.
   * Stock ids have identifiers like Gtk::Stock::OK and Gtk::Stock::APPLY.
   * @param stock_id The stock item.
   * @deprecated Use the constructor that takes a Glib::ustring instead.
   */
  explicit ToggleButton(const StockID& stock_id);
#endif // GTKMM_DISABLE_DEPRECATED

  
  /** Sets whether the button is displayed as a separate indicator and label.
   * You can call this function on a checkbutton or a radiobutton with
   *  @a draw_indicator = <tt>false</tt> to make the button look like a normal button
   * 
   * This function only affects instances of classes like Gtk::CheckButton
   * and Gtk::RadioButton that derive from Gtk::ToggleButton,
   * not instances of Gtk::ToggleButton itself.
   * 
   * @param draw_indicator If <tt>true</tt>, draw the button as a separate indicator
   * and label; if <tt>false</tt>, draw the button like a normal button.
   */
  void set_mode(bool draw_indicator =  true);
  
  /** Retrieves whether the button is displayed as a separate indicator
   * and label. See set_mode().
   * 
   * @return <tt>true</tt> if the togglebutton is drawn as a separate indicator
   * and label.
   */
  bool get_mode() const;

  
  /** Sets the status of the toggle button. Set to <tt>true</tt> if you want the
   * GtkToggleButton to be “pressed in”, and <tt>false</tt> to raise it.
   * This action causes the Gtk::ToggleButton::signal_toggled() signal and the
   * Gtk::Button::signal_clicked() signal to be emitted.
   * 
   * @param is_active <tt>true</tt> or <tt>false</tt>.
   */
  void set_active(bool is_active =  true);
  
  /** Queries a Gtk::ToggleButton and returns its current state. Returns <tt>true</tt> if
   * the toggle button is pressed in and <tt>false</tt> if it is raised.
   * 
   * @return A <tt>bool</tt> value.
   */
  bool get_active() const;

  
  /** If the user has selected a range of elements (such as some text or
   * spreadsheet cells) that are affected by a toggle button, and the
   * current values in that range are inconsistent, you may want to
   * display the toggle in an “in between” state. This function turns on
   * “in between” display.  Normally you would turn off the inconsistent
   * state again if the user toggles the toggle button. This has to be
   * done manually, set_inconsistent() only affects
   * visual appearance, it doesn’t affect the semantics of the button.
   * 
   * @param setting <tt>true</tt> if state is inconsistent.
   */
  void set_inconsistent(bool setting =  true);
  
  /** Gets the value set by set_inconsistent().
   * 
   * @return <tt>true</tt> if the button is displayed as inconsistent, <tt>false</tt> otherwise.
   */
  bool get_inconsistent() const;

  
  /** Emits the Gtk::ToggleButton::signal_toggled() signal on the
   * Gtk::ToggleButton. There is no good reason for an
   * application ever to call this function.
   */
  void toggled();

  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%toggled()</tt>
   *
   * Should be connected if you wish to perform an action whenever the
   * Gtk::ToggleButton's state is changed.
   */

  Glib::SignalProxy0< void > signal_toggled();


  /** If the toggle button should be pressed in.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_active() ;

/** If the toggle button should be pressed in.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_active() const;

  /** If the toggle button is in an 'in between' state.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_inconsistent() ;

/** If the toggle button is in an 'in between' state.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_inconsistent() const;

  /** If the toggle part of the button is displayed.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_draw_indicator() ;

/** If the toggle part of the button is displayed.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_draw_indicator() const;


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
   * @relates Gtk::ToggleButton
   */
  Gtk::ToggleButton* wrap(GtkToggleButton* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_TOGGLEBUTTON_H */

