// -*- c++ -*-
// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!
#ifndef _GDKMM_DRAGCONTEXT_H
#define _GDKMM_DRAGCONTEXT_H


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

#include <vector>

#include <gdkmm/color.h>
#include <gdkmm/pixbuf.h>
#include <gdkmm/device.h>
#include <glibmm/object.h>
#include <cairomm/surface.h>
#include <gdk/gdk.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GdkDragContext GdkDragContext;
typedef struct _GdkDragContextClass GdkDragContextClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class DragContext_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{

/** @addtogroup gdkmmEnums gdkmm Enums and Flags */

/** 
 *  @var DragAction ACTION_DEFAULT
 * Means nothing, and should not be used.
 * 
 *  @var DragAction ACTION_COPY
 * Copy the data.
 * 
 *  @var DragAction ACTION_MOVE
 * Move the data, i.e. first copy it, then delete
 * it from the source using the DELETE target of the X selection protocol.
 * 
 *  @var DragAction ACTION_LINK
 * Add a link to the data. Note that this is only
 * useful if source and destination agree on what it means.
 * 
 *  @var DragAction ACTION_PRIVATE
 * Special action which tells the source that the
 * destination will do something that the source doesn’t understand.
 * 
 *  @var DragAction ACTION_ASK
 * Ask the user what to do with the data.
 * 
 *  @enum DragAction
 * 
 * Used in Gdk::DragContext to indicate what the destination
 * should do with the dropped data.
 *
 * @ingroup gdkmmEnums
 * @par Bitwise operators:
 * <tt>%DragAction operator|(DragAction, DragAction)</tt><br>
 * <tt>%DragAction operator&(DragAction, DragAction)</tt><br>
 * <tt>%DragAction operator^(DragAction, DragAction)</tt><br>
 * <tt>%DragAction operator~(DragAction)</tt><br>
 * <tt>%DragAction& operator|=(DragAction&, DragAction)</tt><br>
 * <tt>%DragAction& operator&=(DragAction&, DragAction)</tt><br>
 * <tt>%DragAction& operator^=(DragAction&, DragAction)</tt><br>
 */
enum DragAction
{
  ACTION_DEFAULT = 1 << 0,
  ACTION_COPY = 1 << 1,
  ACTION_MOVE = 1 << 2,
  ACTION_LINK = 1 << 3,
  ACTION_PRIVATE = 1 << 4,
  ACTION_ASK = 1 << 5
};

/** @ingroup gdkmmEnums */
inline DragAction operator|(DragAction lhs, DragAction rhs)
  { return static_cast<DragAction>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline DragAction operator&(DragAction lhs, DragAction rhs)
  { return static_cast<DragAction>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline DragAction operator^(DragAction lhs, DragAction rhs)
  { return static_cast<DragAction>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline DragAction operator~(DragAction flags)
  { return static_cast<DragAction>(~static_cast<unsigned>(flags)); }

/** @ingroup gdkmmEnums */
inline DragAction& operator|=(DragAction& lhs, DragAction rhs)
  { return (lhs = static_cast<DragAction>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline DragAction& operator&=(DragAction& lhs, DragAction rhs)
  { return (lhs = static_cast<DragAction>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline DragAction& operator^=(DragAction& lhs, DragAction rhs)
  { return (lhs = static_cast<DragAction>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gdk::DragAction> : public Glib::Value_Flags<Gdk::DragAction>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdk
{

/** 
 *  @var DragProtocol DRAG_PROTO_NONE
 * No protocol.
 * 
 *  @var DragProtocol DRAG_PROTO_MOTIF
 * The Motif DND protocol. No longer supported.
 * 
 *  @var DragProtocol DRAG_PROTO_XDND
 * The Xdnd protocol.
 * 
 *  @var DragProtocol DRAG_PROTO_ROOTWIN
 * An extension to the Xdnd protocol for
 * unclaimed root window drops.
 * 
 *  @var DragProtocol DRAG_PROTO_WIN32_DROPFILES
 * The simple WM_DROPFILES protocol.
 * 
 *  @var DragProtocol DRAG_PROTO_OLE2
 * The complex OLE2 DND protocol (not implemented).
 * 
 *  @var DragProtocol DRAG_PROTO_LOCAL
 * Intra-application DND.
 * 
 *  @var DragProtocol DRAG_PROTO_WAYLAND
 * Wayland DND protocol.
 * 
 *  @enum DragProtocol
 * 
 * Used in Gdk::DragContext to indicate the protocol according to
 * which DND is done.
 *
 * @ingroup gdkmmEnums
 */
enum DragProtocol
{
  DRAG_PROTO_NONE,
  DRAG_PROTO_MOTIF,
  DRAG_PROTO_XDND,
  DRAG_PROTO_ROOTWIN,
  DRAG_PROTO_WIN32_DROPFILES,
  DRAG_PROTO_OLE2,
  DRAG_PROTO_LOCAL,
  DRAG_PROTO_WAYLAND
};

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gdk::DragProtocol> : public Glib::Value_Enum<Gdk::DragProtocol>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdk
{


/** A Gdk::DragContext holds information about a drag in progress. It is used on both source and destination sides.
 */

class DragContext : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef DragContext CppObjectType;
  typedef DragContext_Class CppClassType;
  typedef GdkDragContext BaseObjectType;
  typedef GdkDragContextClass BaseClassType;

  // noncopyable
  DragContext(const DragContext&) = delete;
  DragContext& operator=(const DragContext&) = delete;

private:  friend class DragContext_Class;
  static CppClassType dragcontext_class_;

protected:
  explicit DragContext(const Glib::ConstructParams& construct_params);
  explicit DragContext(GdkDragContext* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  DragContext(DragContext&& src) noexcept;
  DragContext& operator=(DragContext&& src) noexcept;

  virtual ~DragContext() noexcept;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GdkDragContext*       gobj()       { return reinterpret_cast<GdkDragContext*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GdkDragContext* gobj() const { return reinterpret_cast<GdkDragContext*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GdkDragContext* gobj_copy();

private:

protected:

public:

  
  /** Selects one of the actions offered by the drag source.
   * 
   * This function is called by the drag destination in response to
   * gdk_drag_motion() called by the drag source.
   * 
   * @param action The selected action which will be taken when a drop happens,
   * or 0 to indicate that a drop will not be accepted.
   * @param time The timestamp for this operation.
   */
  void drag_status(DragAction action, guint32 time);

  /** Indicate that a drop will not be accepted.
   * This function may be called by the drag destination in response to gdk_drag_motion() called by the drag source.
   * Alternatively, call drag_status() to indicate which drag action will be accepted.
   *
   * @param time The timestamp for this operation.
   */
  void drag_refuse(guint32 time);

   //gdk_drag_motion is only used in GDK internally.

  
  /** Accepts or rejects a drop.
   * 
   * This function is called by the drag destination in response
   * to a drop initiated by the drag source.
   * 
   * @param accepted <tt>true</tt> if the drop is accepted.
   * @param time The timestamp for this operation.
   */
  void drop_reply(bool accepted, guint32 time);
  
  /** Ends the drag operation after a drop.
   * 
   * This function is called by the drag destination.
   * 
   * @param success <tt>true</tt> if the data was successfully received.
   * @param time The timestamp for this operation.
   */
  void drop_finish(bool success, guint32 time);
  
  /** Returns the selection atom for the current source window.
   * 
   * @return The selection atom, or Gdk::NONE.
   */
  Glib::ustring get_selection() const;

  //For some reason this is not in our *_docs.xml file.
  
  /** Informs the drag source that the drop is finished, and that the data of the drag will no longer be required.
   * @param success A flag indicating whether the drop was successful.
   * @param del A flag indicating whether the source should delete the original data. (This should be true for a move.)
   * @param time The timestamp from the "drag_data_drop" signal.
   */
  void drag_finish(bool success, bool del, guint32 time);
  //Gtk::Widget* get_source_widget() - see Gtk::Widget::drag_get_source_widget()

  // void set_icon(Gtk::Widget* widget, int hot_x, int hot_y) - see Gtk::Widget::set_as_icon().

   
  void set_icon(const ::Cairo::RefPtr< ::Cairo::Surface>& surface);

  
  void set_icon(const Glib::RefPtr<Gdk::Pixbuf>& pixbuf, int hot_x, int hot_y);

  // The first argument was changed from StockID to ustring to avoid
  // cross-dependence between gdkmm and gtkmm.
  // See http://bugzilla.gnome.org/show_bug.cgi?id=79124 for details
  
#ifndef GDKMM_DISABLE_DEPRECATED

  void set_icon(const Glib::ustring& stock_id, int hot_x, int hot_y);
#endif // GDKMM_DISABLE_DEPRECATED


  void set_icon_name(const Glib::ustring& name, int hot_x, int hot_y);
  
  void set_icon();

  
  /** Returns the Gdk::Window where the DND operation started.
   * 
   * @newin{2,22}
   * 
   * @return A Gdk::Window.
   */
  Glib::RefPtr<Window> get_source_window();
  
  /** Returns the Gdk::Window where the DND operation started.
   * 
   * @newin{2,22}
   * 
   * @return A Gdk::Window.
   */
  Glib::RefPtr<const Window> get_source_window() const;
  
  /** Returns the destination windw for the DND operation.
   * 
   * @newin{3,0}
   * 
   * @return A Gdk::Window.
   */
  Glib::RefPtr<Window> get_dest_window();
  
  /** Returns the destination windw for the DND operation.
   * 
   * @newin{3,0}
   * 
   * @return A Gdk::Window.
   */
  Glib::RefPtr<const Window> get_dest_window() const;
  
  /** Returns the drag protocol thats used by this context.
   * 
   * @newin{3,0}
   * 
   * @return The drag protocol.
   */
  DragProtocol get_protocol() const;


  /** Associates a Gdk::Device to @a context, so all Drag and Drop events
   * for @a context are emitted as if they came from this device.
   * 
   * @param device A Gdk::Device.
   */
  void set_device(const Glib::RefPtr<Device>& device);
  
  /** Returns the Gdk::Device associated to the drag context.
   * 
   * @return The Gdk::Device associated to @a context.
   */
  Glib::RefPtr<Device> get_device();
  
  /** Returns the Gdk::Device associated to the drag context.
   * 
   * @return The Gdk::Device associated to @a context.
   */
  Glib::RefPtr<const Device> get_device() const;

  /** Get a list of targets offered by the source.
   * @result a list of targets offered by the source.
   */
  std::vector<std::string> list_targets() const;
  

  /** Determines the bitmask of actions proposed by the source if
   * get_suggested_action() returns Gdk::ACTION_ASK.
   * 
   * @newin{2,22}
   * 
   * @return The Gdk::DragAction flags.
   */
  DragAction get_actions() const;
  
  /** Determines the suggested drag action of the context.
   * 
   * @newin{2,22}
   * 
   * @return A Gdk::DragAction value.
   */
  DragAction get_suggested_action() const;
  
  /** Determines the action chosen by the drag destination.
   * 
   * @newin{2,22}
   * 
   * @return A Gdk::DragAction value.
   */
  DragAction get_selected_action() const;

  
  /** Finds the destination window and DND protocol to use at the
   * given pointer position.
   * 
   * This function is called by the drag source to obtain the
   *  @a dest_window and @a protocol parameters for gdk_drag_motion().
   * 
   * @newin{2,2}
   * 
   * @param drag_window A window which may be at the pointer position, but
   * should be ignored, since it is put up by the drag source as an icon.
   * @param screen The screen where the destination window is sought.
   * @param x_root The x position of the pointer in root coordinates.
   * @param y_root The y position of the pointer in root coordinates.
   * @param dest_window Location to store the destination window in.
   * @param protocol Location to store the DND protocol in.
   */

  void find_window_for_screen(const Glib::RefPtr<Window>& drag_window, const Glib::RefPtr<Screen>& screen, int x_root, int y_root, Glib::RefPtr<Window>& dest_window, DragProtocol& protocol) const;
  

public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gdk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::DragContext
   */
  Glib::RefPtr<Gdk::DragContext> wrap(GdkDragContext* object, bool take_copy = false);
}


#endif /* _GDKMM_DRAGCONTEXT_H */

