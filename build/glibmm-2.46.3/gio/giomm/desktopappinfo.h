// -*- c++ -*-
// Generated by gmmproc 2.46.3 -- DO NOT MODIFY!
#ifndef _GIOMM_DESKTOPAPPINFO_H
#define _GIOMM_DESKTOPAPPINFO_H

#include <giommconfig.h>


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The gtkmm Development Team
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


#include <glibmm/object.h>
#include <giomm/appinfo.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GDesktopAppInfo GDesktopAppInfo;
typedef struct _GDesktopAppInfoClass GDesktopAppInfoClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class DesktopAppInfo_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Glib
{

class KeyFile;

}

namespace Gio
{

/**
 * DesktopAppInfo is an implementation of AppInfo based on desktop files.
 *
 * @newin{2,16}
 */

class DesktopAppInfo
: public Glib::Object,
  public AppInfo
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef DesktopAppInfo CppObjectType;
  typedef DesktopAppInfo_Class CppClassType;
  typedef GDesktopAppInfo BaseObjectType;
  typedef GDesktopAppInfoClass BaseClassType;

  // noncopyable
  DesktopAppInfo(const DesktopAppInfo&) = delete;
  DesktopAppInfo& operator=(const DesktopAppInfo&) = delete;

private:  friend class DesktopAppInfo_Class;
  static CppClassType desktopappinfo_class_;

protected:
  explicit DesktopAppInfo(const Glib::ConstructParams& construct_params);
  explicit DesktopAppInfo(GDesktopAppInfo* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  DesktopAppInfo(DesktopAppInfo&& src) noexcept;
  DesktopAppInfo& operator=(DesktopAppInfo&& src) noexcept;

  virtual ~DesktopAppInfo() noexcept;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GDesktopAppInfo*       gobj()       { return reinterpret_cast<GDesktopAppInfo*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GDesktopAppInfo* gobj() const { return reinterpret_cast<GDesktopAppInfo*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GDesktopAppInfo* gobj_copy();

private:

  
  //This is not available on Win32.
//This source file will not be compiled on Win32,
//and no class defined in it will be registered by wrap_init().


public:
  // TODO: should use _WRAP_CREATE(), but these functions do more than just call
  // g_object_new() because there's quite a bit of error-handling to do.
  
  /** Creates a new DesktopAppInfo based on a desktop file id.
   * 
   * A desktop file id is the basename of the desktop file, including the
   * .desktop extension. GIO is looking for a desktop file with this name
   * in the `applications` subdirectories of the XDG
   * data directories (i.e. the directories specified in the `XDG_DATA_HOME`
   * and `XDG_DATA_DIRS` environment variables). GIO also supports the
   * prefix-to-subdirectory mapping that is described in the
   * [Menu Spec](http://standards.freedesktop.org/menu-spec/latest/)
   * (i.e. a desktop id of kde-foo.desktop will match
   * `/usr/share/applications/kde/foo.desktop`).
   * 
   * @param desktop_id The desktop file id.
   * @return A new DesktopAppInfo, or <tt>0</tt> if no desktop file with that id.
   */
  static Glib::RefPtr<DesktopAppInfo> create(const std::string& desktop_id);
  
  /** Creates a new DesktopAppInfo.
   * 
   * @newin{2,18}
   * 
   * @param key_file An opened KeyFile.
   * @return A new DesktopAppInfo or <tt>0</tt> on error.
   */
  static Glib::RefPtr<DesktopAppInfo> create_from_keyfile(Glib::KeyFile& key_file);
  
  /** Creates a new DesktopAppInfo.
   * 
   * @param filename The path of a desktop file, in the GLib filename encoding.
   * @return A new DesktopAppInfo or <tt>0</tt> on error.
   */
  static Glib::RefPtr<DesktopAppInfo> create_from_filename(const std::string& filename);

  
  /** When @a info was created from a known filename, return it.  In some
   * situations such as the DesktopAppInfo returned from
   * g_desktop_app_info_new_from_keyfile(), this function will return <tt>0</tt>.
   * 
   * @newin{2,24}
   * 
   * @return The full path to the file for @a info, or <tt>0</tt> if not known.
   */
  std::string get_filename() const;
  
  /** A desktop file is hidden if the Hidden key in it is
   * set to True.
   * 
   * @return <tt>true</tt> if hidden, <tt>false</tt> otherwise.
   */
  bool is_hidden() const;
  
#ifndef GIOMM_DISABLE_DEPRECATED

  /** Sets the name of the desktop that the application is running in.
   * This is used by g_app_info_should_show() and
   * g_desktop_app_info_get_show_in() to evaluate the
   * `OnlyShowIn` and `NotShowIn`
   * desktop entry fields.
   * 
   * Should be called only once; subsequent calls are ignored.
   * 
   * Deprecated:2.42:do not use this API.  Since 2.42 the value of the
   * `XDG_CURRENT_DESKTOP` environment variable will be used.
   * 
   * @deprecated Do not use this API. Since 2.42 the value of the `XDG_CURRENT_DESKTOP` environment variable will be used.
   * 
   * @param desktop_env A string specifying what desktop this is.
   */
  static void set_desktop_env(const std::string& desktop_env);
#endif // GIOMM_DISABLE_DEPRECATED


  /** Gets the keywords from the desktop file.
   * 
   * @newin{2,32}
   * 
   * @return The value of the Keywords key.
   */
  std::vector<Glib::ustring> get_keywords() const;

  
  /** Retrieves the StartupWMClass field from @a info. This represents the
   * WM_CLASS property of the main window of the application, if launched
   * through @a info.
   * 
   * @newin{2,34}
   * 
   * @return The startup WM class, or <tt>0</tt> if none is set
   * in the desktop file.
   */
  std::string get_startup_wm_class() const;
  
  /** Gets the value of the NoDisplay key, which helps determine if the
   * application info should be shown in menus. See
   * KEY_FILE_DESKTOP_KEY_NO_DISPLAY and g_app_info_should_show().
   * 
   * @newin{2,30}
   * 
   * @return The value of the NoDisplay key.
   */
  bool get_nodisplay() const;
  
  /** Checks if the application info should be shown in menus that list available
   * applications for a specific name of the desktop, based on the
   * `OnlyShowIn` and `NotShowIn` keys.
   * 
   *  @a desktop_env should typically be given as <tt>0</tt>, in which case the
   * `XDG_CURRENT_DESKTOP` environment variable is consulted.  If you want
   * to override the default mechanism then you may specify @a desktop_env,
   * but this is not recommended.
   * 
   * Note that g_app_info_should_show() for @a info will include this check (with
   * <tt>0</tt> for @a desktop_env) as well as additional checks.
   * 
   * @newin{2,30}
   * 
   * @param desktop_env A string specifying a desktop name.
   * @return <tt>true</tt> if the @a info should be shown in @a desktop_env according to the
   * `OnlyShowIn` and `NotShowIn` keys, <tt>false</tt>
   * otherwise.
   */
  bool get_show_in(const std::string& desktop_env) const;
  
  /** Gets the generic name from the destkop file.
   * 
   * @return The value of the GenericName key.
   */
  std::string get_generic_name() const;
  
  /** Gets the categories from the desktop file.
   * 
   * @return The unparsed Categories key from the desktop file;
   * i.e. no attempt is made to split it by ';' or validate it.
   */
  std::string get_categories() const;

  
  /** Returns whether @a key exists in the "Desktop Entry" group
   * of the keyfile backing @a info.
   * 
   * @newin{2,36}
   * 
   * @param key The key to look up.
   * @return <tt>true</tt> if the @a key exists.
   */
  bool has_key(const Glib::ustring& key) const;
  
  /** Looks up a string value in the keyfile backing @a info.
   * 
   * The @a key is looked up in the "Desktop Entry" group.
   * 
   * @newin{2,36}
   * 
   * @param key The key to look up.
   * @return A newly allocated string, or <tt>0</tt> if the key
   * is not found.
   */
  Glib::ustring get_string(const Glib::ustring& key);
  
  /** Looks up a boolean value in the keyfile backing @a info.
   * 
   * The @a key is looked up in the "Desktop Entry" group.
   * 
   * @newin{2,36}
   * 
   * @param key The key to look up.
   * @return The boolean value, or <tt>false</tt> if the key
   * is not found.
   */
  bool get_boolean(const Glib::ustring& key) const;

 
  /** Returns the list of "additional application actions" supported on the
   * desktop file, as per the desktop file specification.
   * 
   * As per the specification, this is the list of actions that are
   * explicitly listed in the "Actions" key of the [Desktop Entry] group.
   * 
   * @newin{2,38}
   * 
   * @return A list of strings, always non-<tt>0</tt>.
   */
  std::vector<Glib::ustring> list_actions() const;

  
  /** Activates the named application action.
   * 
   * You may only call this function on action names that were
   * returned from g_desktop_app_info_list_actions().
   * 
   * Note that if the main entry of the desktop file indicates that the
   * application supports startup notification, and @a launch_context is
   * non-<tt>0</tt>, then startup notification will be used when activating the
   * action (and as such, invocation of the action on the receiving side
   * must signal the end of startup notification when it is completed).
   * This is the expected behaviour of applications declaring additional
   * actions, as per the desktop file specification.
   * 
   * As with g_app_info_launch() there is no way to detect failures that
   * occur while using this function.
   * 
   * @newin{2,38}
   * 
   * @param action_name The name of the action as from
   * g_desktop_app_info_list_actions().
   * @param launch_context A AppLaunchContext.
   */
  void launch_action(const Glib::ustring& action_name, const Glib::RefPtr<AppLaunchContext>& launch_context);

  /// A launch_action() convenience overload.
  void launch_action(const Glib::ustring& action_name);

  
  /** Gets the user-visible display name of the "additional application
   * action" specified by @a action_name.
   * 
   * This corresponds to the "Name" key within the keyfile group for the
   * action.
   * 
   * @newin{2,38}
   * 
   * @param action_name The name of the action as from
   * g_desktop_app_info_list_actions().
   * @return The locale-specific action name.
   */
  Glib::ustring get_action_name(const Glib::ustring& action_name) const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::DesktopAppInfo
   */
  Glib::RefPtr<Gio::DesktopAppInfo> wrap(GDesktopAppInfo* object, bool take_copy = false);
}


#endif /* _GIOMM_DESKTOPAPPINFO_H */

