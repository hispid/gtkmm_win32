// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gdkmm/device.h>
#include <gdkmm/private/device_p.h>


/* Copyright 2002 The gtkmm Development Team
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

#include <gdk/gdk.h>
#include <gdkmm/cursor.h>
#include <gdkmm/display.h>
#include <gdkmm/window.h>

namespace Gdk
{

std::vector<TimeCoord> Device::get_history(const Glib::RefPtr<Window>& window, guint32 start, guint32 stop) const
{
  GdkTimeCoord** coords = nullptr;
  int events_count = 0;

  // we don't care about returned value - false means that either getting history is unsupported or no motion events happened.
  // it is undistinguishable.
  gdk_device_get_history(const_cast<GdkDevice*>(gobj()), Glib::unwrap(window), start, stop, &coords, &events_count);
  return Glib::ArrayHandler<TimeCoord, TimeCoordPtrTraits>::array_to_vector(coords, events_count, Glib::OWNERSHIP_DEEP);
}

void Device::get_position(int& x, int& y) const
{
  gdk_device_get_position(const_cast<GdkDevice*>(gobj()), 0, &x, &y);
}

void Device::get_position(Glib::RefPtr<Screen>& screen, int& x, int& y) const
{
  GdkScreen* cScreen = nullptr;
  gdk_device_get_position(const_cast<GdkDevice*>(gobj()), &cScreen, &x, &y);
  screen = Glib::wrap(cScreen, true);
}

void Device::get_position(double& x, double& y) const
{
  gdk_device_get_position_double(const_cast<GdkDevice*>(gobj()), 0, &x, &y);
}

void Device::get_position(Glib::RefPtr<Screen>& screen, double& x, double& y) const
{
  GdkScreen* cScreen = nullptr;
  gdk_device_get_position_double(const_cast<GdkDevice*>(gobj()), &cScreen, &x, &y);
  screen = Glib::wrap(cScreen, true);
}

Glib::RefPtr<Window> Device::get_window_at_position()
{
  auto retvalue = Glib::wrap(gdk_device_get_window_at_position(gobj(), 0, 0));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Window> Device::get_window_at_position() const
{
  return const_cast<Device*>(this)->get_window_at_position();
}

GrabStatus Device::grab(const Glib::RefPtr<Window>& window, GrabOwnership grab_ownership, bool owner_events, EventMask event_mask, guint32 time_)
{
  return static_cast<GrabStatus>(gdk_device_grab(gobj(), Glib::unwrap(window), static_cast<GdkGrabOwnership>(grab_ownership), static_cast<int>(owner_events), static_cast<GdkEventMask>(event_mask), 0, time_));
}

std::vector<std::string> Device::list_axes() const
{
  auto glist = gdk_device_list_axes(const_cast<GdkDevice*>(gobj()));
  return Glib::ListHandler<std::string, AtomStringTraits>::list_to_vector(glist, Glib::OWNERSHIP_SHALLOW);
}

} // namespace Gdk


namespace
{
} // anonymous namespace

// static
GType Glib::Value<Gdk::EventMask>::value_type()
{
  return gdk_event_mask_get_type();
}

// static
GType Glib::Value<Gdk::InputMode>::value_type()
{
  return gdk_input_mode_get_type();
}

// static
GType Glib::Value<Gdk::InputSource>::value_type()
{
  return gdk_input_source_get_type();
}

// static
GType Glib::Value<Gdk::DeviceType>::value_type()
{
  return gdk_device_type_get_type();
}

// static
GType Glib::Value<Gdk::GrabOwnership>::value_type()
{
  return gdk_grab_ownership_get_type();
}

// static
GType Glib::Value<Gdk::GrabStatus>::value_type()
{
  return gdk_grab_status_get_type();
}


namespace Glib
{

Glib::RefPtr<Gdk::Device> wrap(GdkDevice* object, bool take_copy)
{
  return Glib::RefPtr<Gdk::Device>( dynamic_cast<Gdk::Device*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

const Glib::Class& Device_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Device_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_device_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void Device_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* Device_Class::wrap_new(GObject* object)
{
  return new Device((GdkDevice*)object);
}


/* The implementation: */

GdkDevice* Device::gobj_copy()
{
  reference();
  return gobj();
}

Device::Device(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

Device::Device(GdkDevice* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


Device::Device(Device&& src) noexcept
: Glib::Object(std::move(src))
{}

Device& Device::operator=(Device&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  return *this;
}

Device::~Device() noexcept
{}


Device::CppClassType Device::device_class_; // initialize static member

GType Device::get_type()
{
  return device_class_.init().get_type();
}


GType Device::get_base_type()
{
  return gdk_device_get_type();
}


Device::Device()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(device_class_.init()))
{
  

}

Glib::ustring Device::get_name() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(gdk_device_get_name(const_cast<GdkDevice*>(gobj())));
}

bool Device::get_has_cursor() const
{
  return gdk_device_get_has_cursor(const_cast<GdkDevice*>(gobj()));
}

InputSource Device::get_source() const
{
  return ((InputSource)(gdk_device_get_source(const_cast<GdkDevice*>(gobj()))));
}

InputMode Device::get_mode() const
{
  return ((InputMode)(gdk_device_get_mode(const_cast<GdkDevice*>(gobj()))));
}

bool Device::set_mode(InputMode mode)
{
  return gdk_device_set_mode(gobj(), ((GdkInputMode)(mode)));
}

int Device::get_n_keys() const
{
  return gdk_device_get_n_keys(const_cast<GdkDevice*>(gobj()));
}

bool Device::get_key(guint index_, guint& keyval, ModifierType& modifiers) const
{
  return gdk_device_get_key(const_cast<GdkDevice*>(gobj()), index_, &(keyval), ((GdkModifierType*) &(modifiers)));
}

void Device::set_key(guint index_, guint keyval, ModifierType modifiers)
{
  gdk_device_set_key(gobj(), index_, keyval, ((GdkModifierType)(modifiers)));
}

AxisUse Device::get_axis_use(guint index_) const
{
  return ((AxisUse)(gdk_device_get_axis_use(const_cast<GdkDevice*>(gobj()), index_)));
}

void Device::set_axis_use(guint index_, AxisUse use)
{
  gdk_device_set_axis_use(gobj(), index_, ((GdkAxisUse)(use)));
}

void Device::get_state(const Glib::RefPtr<Window>& window, double& axes, ModifierType& mask)
{
  gdk_device_get_state(gobj(), Glib::unwrap(window), &(axes), ((GdkModifierType*) &(mask)));
}

std::vector<Glib::RefPtr<Gdk::Device> > Device::list_slave_devices()
{
  return Glib::ListHandler<Glib::RefPtr<Gdk::Device> >::list_to_vector(gdk_device_list_slave_devices(gobj()), Glib::OWNERSHIP_SHALLOW);
}

int Device::get_n_axes() const
{
  return gdk_device_get_n_axes(const_cast<GdkDevice*>(gobj()));
}

bool Device::get_axis_value(double& axes, GdkAtom axis_label, double& value) const
{
  return gdk_device_get_axis_value(const_cast<GdkDevice*>(gobj()), &(axes), axis_label, &(value));
}

bool Device::get_axis(double& axes, AxisUse use, double& value) const
{
  return gdk_device_get_axis(const_cast<GdkDevice*>(gobj()), &(axes), ((GdkAxisUse)(use)), &(value));
}

Glib::RefPtr<Display> Device::get_display()
{
  Glib::RefPtr<Display> retvalue = Glib::wrap(gdk_device_get_display(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Display> Device::get_display() const
{
  return const_cast<Device*>(this)->get_display();
}

Glib::RefPtr<Device> Device::get_associated_device()
{
  Glib::RefPtr<Device> retvalue = Glib::wrap(gdk_device_get_associated_device(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Device> Device::get_associated_device() const
{
  return const_cast<Device*>(this)->get_associated_device();
}

DeviceType Device::get_device_type() const
{
  return ((DeviceType)(gdk_device_get_device_type(const_cast<GdkDevice*>(gobj()))));
}

GrabStatus Device::grab(const Glib::RefPtr<Window>& window, GrabOwnership grab_ownership, bool owner_events, EventMask event_mask, const Glib::RefPtr<Cursor>& cursor, guint32 time_)
{
  return ((GrabStatus)(gdk_device_grab(gobj(), Glib::unwrap(window), ((GdkGrabOwnership)(grab_ownership)), static_cast<int>(owner_events), ((GdkEventMask)(event_mask)), Glib::unwrap(cursor), time_)));
}

void Device::ungrab(guint32 time_)
{
  gdk_device_ungrab(gobj(), time_);
}

void Device::warp(const Glib::RefPtr<Screen>& screen, int x, int y)
{
  gdk_device_warp(gobj(), Glib::unwrap(screen), x, y);
}

Glib::RefPtr<Window> Device::get_window_at_position(int& win_x, int& win_y)
{
  Glib::RefPtr<Window> retvalue = Glib::wrap(gdk_device_get_window_at_position(gobj(), &(win_x), &(win_y)));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Window> Device::get_window_at_position(int& win_x, int& win_y) const
{
  return const_cast<Device*>(this)->get_window_at_position(win_x, win_y);
}

Glib::RefPtr<Window> Device::get_last_event_window()
{
  Glib::RefPtr<Window> retvalue = Glib::wrap(gdk_device_get_last_event_window(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Window> Device::get_last_event_window() const
{
  return const_cast<Device*>(this)->get_last_event_window();
}

Glib::ustring Device::get_vendor_id() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(gdk_device_get_vendor_id(const_cast<GdkDevice*>(gobj())));
}

Glib::ustring Device::get_product_id()
{
  return Glib::convert_const_gchar_ptr_to_ustring(gdk_device_get_product_id(gobj()));
}


} // namespace Gdk


