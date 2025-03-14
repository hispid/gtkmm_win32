// -*- c++ -*-
// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!
#ifndef _GTKMM_EXPANDER_H
#define _GTKMM_EXPANDER_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2003 The gtkmm Development Team
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

#include <gtkmm/bin.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkExpander GtkExpander;
typedef struct _GtkExpanderClass GtkExpanderClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class Expander_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A container which can hide its child.
 *
 * An Expander allows the user to hide or show its child by clicking on an
 * expander triangle similar to the triangles used in a Gtk::TreeView.
 *
 * Normally you use an expander as you would use any other descendant
 * of Gtk::Bin; you create the child widget and use add() to add it to
 * the expander.  When the expander is toggled, it will take care of
 * showing and hiding the child automatically.
 *
 * Special Usage: There are situations in which you may prefer to show and
 * hide the expanded widget yourself, such as when you want to
 * actually create the widget at expansion time.  In this case,
 * create an Expander but do not add a child to it.  The
 * expander widget has an <tt>expanded</tt> property
 * which can be used to monitor its expansion state.  You should
 * watch this property with a signal connection as follows:
 * @code
 * expander.property_expanded().signal_changed().connect(
 *   sigc::mem_fun(*this, &SomeClass::on_expander_changed)
 * );
 * @endcode
 *
 * @ingroup Widgets
 * @ingroup Containers
 */

class Expander : public Bin
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Expander CppObjectType;
  typedef Expander_Class CppClassType;
  typedef GtkExpander BaseObjectType;
  typedef GtkExpanderClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Expander(Expander&& src) noexcept;
  Expander& operator=(Expander&& src) noexcept;

  // noncopyable
  Expander(const Expander&) = delete;
  Expander& operator=(const Expander&) = delete;

  virtual ~Expander() noexcept;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class Expander_Class;
  static CppClassType expander_class_;

protected:
  explicit Expander(const Glib::ConstructParams& construct_params);
  explicit Expander(GtkExpander* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkExpander*       gobj()       { return reinterpret_cast<GtkExpander*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkExpander* gobj() const { return reinterpret_cast<GtkExpander*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

public:

  /** Creates a new Expander.
   *
   * The Expander has an empty label.
   *
   * @newin{2,4}
   */
  Expander();

  /** Creates a new Expander with a label.
   *
   * Creates a new expander using label as the text of the label. Settin @a mnemonic to true
   * will allow you to precede characters in the label with an underscore which will make them
   * underlined. If you need a literal underscore character in a label, use '__' (two underscores).
   * The first underlined character represents a keyboard accelerator called a mnemonic.
   * Pressing Alt and that key activates the button.
   *
   * @param label The string for the label describing the Expander.
   * @param mnemonic Wether the label may contain underscores to set up accelerators.

   * @newin{2,4}
   */
  explicit Expander(const Glib::ustring& label, bool mnemonic = false);
  

  /** Sets the state of the expander. Set to <tt>true</tt>, if you want
   * the child widget to be revealed, and <tt>false</tt> if you want the
   * child widget to be hidden.
   * 
   * @newin{2,4}
   * 
   * @param expanded Whether the child widget is revealed.
   */
  void set_expanded(bool expanded =  true);
  
  /** Queries a Gtk::Expander and returns its current state. Returns <tt>true</tt>
   * if the child widget is revealed.
   * 
   * See set_expanded().
   * 
   * @newin{2,4}
   * 
   * @return The current state of the expander.
   */
  bool get_expanded() const;

  
  /** Sets the spacing field of @a expander, which is the number of
   * pixels to place between expander and the child.
   * 
   * @newin{2,4}
   * 
   * @param spacing Distance between the expander and child in pixels.
   */
  void set_spacing(int spacing);
  
  /** Gets the value set by set_spacing().
   * 
   * @newin{2,4}
   * 
   * @return Spacing between the expander and child.
   */
  int get_spacing() const;

  
  /** Sets the text of the label of the expander to @a label.
   * 
   * This will also clear any previously set labels.
   * 
   * @newin{2,4}
   * 
   * @param label A string.
   */
  void set_label(const Glib::ustring& label);
  
  /** Fetches the text from a label widget including any embedded
   * underlines indicating mnemonics and Pango markup, as set by
   * set_label(). If the label text has not been set the
   * return value will be <tt>0</tt>. This will be the case if you create an
   * empty button with Gtk::Button::new() to use as a container.
   * 
   * Note that this function behaved differently in versions prior to
   * 2.14 and used to return the label text stripped of embedded
   * underlines indicating mnemonics and Pango markup. This problem can
   * be avoided by fetching the label text directly from the label
   * widget.
   * 
   * @newin{2,4}
   * 
   * @return The text of the label widget. This string is owned
   * by the widget and must not be modified or freed.
   */
  Glib::ustring get_label() const;

  
  /** If true, an underline in the text of the expander label indicates
   * the next character should be used for the mnemonic accelerator key.
   * 
   * @newin{2,4}
   * 
   * @param use_underline <tt>true</tt> if underlines in the text indicate mnemonics.
   */
  void set_use_underline(bool use_underline =  true);
  
  /** Returns whether an embedded underline in the expander label
   * indicates a mnemonic. See set_use_underline().
   * 
   * @newin{2,4}
   * 
   * @return <tt>true</tt> if an embedded underline in the expander
   * label indicates the mnemonic accelerator keys.
   */
  bool get_use_underline() const;

  
  /** Sets whether the text of the label contains markup in
   * [Pango’s text markup language][PangoMarkupFormat].
   * See Gtk::Label::set_markup().
   * 
   * @newin{2,4}
   * 
   * @param use_markup <tt>true</tt> if the label’s text should be parsed for markup.
   */
  void set_use_markup(bool use_markup =  true);
  
  /** Returns whether the label’s text is interpreted as marked up with
   * the [Pango text markup language][PangoMarkupFormat].
   * See set_use_markup().
   * 
   * @newin{2,4}
   * 
   * @return <tt>true</tt> if the label’s text will be parsed for markup.
   */
  bool get_use_markup() const;

  
  /** Set the label widget for the expander. This is the widget
   * that will appear embedded alongside the expander arrow.
   * 
   * @newin{2,4}
   * 
   * @param label_widget The new label widget.
   */
  void set_label_widget(Widget& label_widget);
  
  /** Retrieves the label widget for the frame. See
   * set_label_widget().
   * 
   * @newin{2,4}
   * 
   * @return The label widget,
   * or <tt>0</tt> if there is none.
   */
  Widget* get_label_widget();
  
  /** Retrieves the label widget for the frame. See
   * set_label_widget().
   * 
   * @newin{2,4}
   * 
   * @return The label widget,
   * or <tt>0</tt> if there is none.
   */
  const Widget* get_label_widget() const;

  
  /** Sets whether the label widget should fill all available
   * horizontal space allocated to @a expander.
   * 
   * @newin{2,22}
   * 
   * @param label_fill <tt>true</tt> if the label should should fill
   * all available horizontal space.
   */
  void set_label_fill(bool label_fill =  true);
  
  /** Returns whether the label widget will fill all available
   * horizontal space allocated to @a expander.
   * 
   * @newin{2,22}
   * 
   * @return <tt>true</tt> if the label widget will fill all
   * available horizontal space.
   */
  bool get_label_fill() const;

  
  /** Sets whether the expander will resize the toplevel widget
   * containing the expander upon resizing and collpasing.
   * 
   * @newin{3,2}
   * 
   * @param resize_toplevel Whether to resize the toplevel.
   */
  void set_resize_toplevel(bool resize_toplevel =  true);
  
  /** Returns whether the expander will resize the toplevel widget
   * containing the expander upon resizing and collpasing.
   * 
   * @newin{3,2}
   * 
   * @return The “resize toplevel” setting.
   */
  bool get_resize_toplevel() const;

   //keybinding

  /** Whether the expander has been opened to reveal the child widget.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_expanded() ;

/** Whether the expander has been opened to reveal the child widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_expanded() const;

  /** Text of the expander's label.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Glib::ustring > property_label() ;

/** Text of the expander's label.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::ustring > property_label() const;

  /** If set, an underline in the text indicates the next character should be used for the mnemonic accelerator key.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_use_underline() ;

/** If set, an underline in the text indicates the next character should be used for the mnemonic accelerator key.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_use_underline() const;

  /** The text of the label includes XML markup. See pango_parse_markup().
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_use_markup() ;

/** The text of the label includes XML markup. See pango_parse_markup().
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_use_markup() const;

  /** Space to put between the label and the child.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< int > property_spacing() ;

/** Space to put between the label and the child.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_spacing() const;

  /** A widget to display in place of the usual expander label.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Widget* > property_label_widget() ;

/** A widget to display in place of the usual expander label.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Widget* > property_label_widget() const;

  /** Whether the label widget should fill all available horizontal space.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_label_fill() ;

/** Whether the label widget should fill all available horizontal space.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_label_fill() const;

  /** When this property is <tt>true</tt>, the expander will resize the toplevel
   * widget containing the expander upon expanding and collapsing.
   * 
   * @newin{3,2}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_resize_toplevel() ;

/** When this property is <tt>true</tt>, the expander will resize the toplevel
   * widget containing the expander upon expanding and collapsing.
   * 
   * @newin{3,2}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_resize_toplevel() const;


};


} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Expander
   */
  Gtk::Expander* wrap(GtkExpander* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_EXPANDER_H */

