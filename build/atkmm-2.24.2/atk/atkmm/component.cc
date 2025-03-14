// Generated by gmmproc 2.47.3.1 -- DO NOT MODIFY!


#include <glibmm.h>

#include <atkmm/component.h>
#include <atkmm/private/component_p.h>

#include <atk/atk-enum-types.h>

// -*- c++ -*-
/* $Id: component.ccg,v 1.1 2003/01/21 13:37:05 murrayc Exp $ */

/* Copyright 1998-2002 The gtkmm Development Team
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

#include <atkmm/object.h>
#include <atk/atkcomponent.h>


namespace
{
} // anonymous namespace

// static
GType Glib::Value<Atk::CoordType>::value_type()
{
  return atk_coord_type_get_type();
}

// static
GType Glib::Value<Atk::Layer>::value_type()
{
  return atk_layer_get_type();
}


namespace Glib
{

Glib::RefPtr<Atk::Component> wrap(AtkComponent* object, bool take_copy)
{
  return Glib::RefPtr<Atk::Component>( dynamic_cast<Atk::Component*> (Glib::wrap_auto_interface<Atk::Component> ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Atk
{


/* The *_Class implementation: */

const Glib::Interface_Class& Component_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &Component_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = atk_component_get_type();
  }

  return *this;
}

void Component_Class::iface_init_function(void* g_iface, void*)
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr); 

  klass->add_focus_handler = &add_focus_handler_vfunc_callback;
  klass->contains = &contains_vfunc_callback;
  klass->ref_accessible_at_point = &ref_accessible_at_point_vfunc_callback;
  klass->get_extents = &get_extents_vfunc_callback;
  klass->get_position = &get_position_vfunc_callback;
  klass->get_size = &get_size_vfunc_callback;
  klass->get_layer = &get_layer_vfunc_callback;
  klass->get_mdi_zorder = &get_mdi_zorder_vfunc_callback;
  klass->grab_focus = &grab_focus_vfunc_callback;
  klass->remove_focus_handler = &remove_focus_handler_vfunc_callback;
  klass->set_extents = &set_extents_vfunc_callback;
  klass->set_position = &set_position_vfunc_callback;
  klass->set_size = &set_size_vfunc_callback;

}

guint Component_Class::add_focus_handler_vfunc_callback(AtkComponent* self, AtkFocusHandler handler)
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
        return obj->add_focus_handler_vfunc(handler);
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->add_focus_handler)
  {
    guint retval = (*base->add_focus_handler)(self, handler);
    return retval;
  }

  typedef guint RType;
  return RType();
}
gboolean Component_Class::contains_vfunc_callback(AtkComponent* self, gint x, gint y, AtkCoordType coord_type)
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
        return static_cast<int>(obj->contains_vfunc(x
, y
, ((CoordType)(coord_type))
));
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->contains)
  {
    gboolean retval = (*base->contains)(self, x, y, coord_type);
    return retval;
  }

  typedef gboolean RType;
  return RType();
}
AtkObject* Component_Class::ref_accessible_at_point_vfunc_callback(AtkComponent* self, gint x, gint y, AtkCoordType coord_type)
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
        return Glib::unwrap_copy(obj->get_accessible_at_point_vfunc(x
, y
, ((CoordType)(coord_type))
));
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->ref_accessible_at_point)
  {
    AtkObject* retval = (*base->ref_accessible_at_point)(self, x, y, coord_type);
    return retval;
  }

  typedef AtkObject* RType;
  return RType();
}
void Component_Class::get_extents_vfunc_callback(AtkComponent* self, gint* x, gint* y, gint* width, gint* height, AtkCoordType coord_type)
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
        obj->get_extents_vfunc(*(x)
, *(y)
, *(width)
, *(height)
, ((CoordType)(coord_type))
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_extents)
  {
    (*base->get_extents)(self, x, y, width, height, coord_type);
  }

}
void Component_Class::get_position_vfunc_callback(AtkComponent* self, gint* x, gint* y, AtkCoordType coord_type)
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
        obj->get_position_vfunc(*(x)
, *(y)
, ((CoordType)(coord_type))
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_position)
  {
    (*base->get_position)(self, x, y, coord_type);
  }

}
void Component_Class::get_size_vfunc_callback(AtkComponent* self, gint* width, gint* height)
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
        obj->get_size_vfunc(*(width)
, *(height)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_size)
  {
    (*base->get_size)(self, width, height);
  }

}
AtkLayer Component_Class::get_layer_vfunc_callback(AtkComponent* self)
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
        return ((AtkLayer)(obj->get_layer_vfunc()));
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_layer)
  {
    AtkLayer retval = (*base->get_layer)(self);
    return retval;
  }

  typedef AtkLayer RType;
  return RType();
}
gint Component_Class::get_mdi_zorder_vfunc_callback(AtkComponent* self)
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
        return obj->get_mdi_zorder_vfunc();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_mdi_zorder)
  {
    gint retval = (*base->get_mdi_zorder)(self);
    return retval;
  }

  typedef gint RType;
  return RType();
}
gboolean Component_Class::grab_focus_vfunc_callback(AtkComponent* self)
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
        return static_cast<int>(obj->grab_focus_vfunc());
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->grab_focus)
  {
    gboolean retval = (*base->grab_focus)(self);
    return retval;
  }

  typedef gboolean RType;
  return RType();
}
void Component_Class::remove_focus_handler_vfunc_callback(AtkComponent* self, guint handler_id)
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
        obj->remove_focus_handler_vfunc(handler_id);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->remove_focus_handler)
  {
    (*base->remove_focus_handler)(self, handler_id);
  }

}
gboolean Component_Class::set_extents_vfunc_callback(AtkComponent* self, gint x, gint y, gint width, gint height, AtkCoordType coord_type)
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
        return static_cast<int>(obj->set_extents_vfunc(x
, y
, width
, height
, ((CoordType)(coord_type))
));
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->set_extents)
  {
    gboolean retval = (*base->set_extents)(self, x, y, width, height, coord_type);
    return retval;
  }

  typedef gboolean RType;
  return RType();
}
gboolean Component_Class::set_position_vfunc_callback(AtkComponent* self, gint x, gint y, AtkCoordType coord_type)
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
        return static_cast<int>(obj->set_position_vfunc(x
, y
, ((CoordType)(coord_type))
));
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->set_position)
  {
    gboolean retval = (*base->set_position)(self, x, y, coord_type);
    return retval;
  }

  typedef gboolean RType;
  return RType();
}
gboolean Component_Class::set_size_vfunc_callback(AtkComponent* self, gint width, gint height)
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
        return static_cast<int>(obj->set_size_vfunc(width
, height
));
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->set_size)
  {
    gboolean retval = (*base->set_size)(self, width, height);
    return retval;
  }

  typedef gboolean RType;
  return RType();
}


Glib::ObjectBase* Component_Class::wrap_new(GObject* object)
{
  return new Component((AtkComponent*)(object));
}


/* The implementation: */

Component::Component()
:
  Glib::Interface(component_class_.init())
{}

Component::Component(AtkComponent* castitem)
:
  Glib::Interface((GObject*)(castitem))
{}

Component::Component(const Glib::Interface_Class& interface_class)
: Glib::Interface(interface_class)
{
}

Component::Component(Component&& src) noexcept
: Glib::Interface(std::move(src))
{}

Component& Component::operator=(Component&& src) noexcept
{
  Glib::Interface::operator=(std::move(src));
  return *this;
}

Component::~Component() noexcept
{}

// static
void Component::add_interface(GType gtype_implementer)
{
  component_class_.init().add_interface(gtype_implementer);
}

Component::CppClassType Component::component_class_; // initialize static member

GType Component::get_type()
{
  return component_class_.init().get_type();
}


GType Component::get_base_type()
{
  return atk_component_get_type();
}


#ifndef ATKMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
guint Component::add_focus_handler(AtkFocusHandler handler)
{
  return atk_component_add_focus_handler(gobj(), handler);
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // ATKMM_DISABLE_DEPRECATED

bool Component::contains(int x, int y, CoordType coord_type) const
{
  return atk_component_contains(const_cast<AtkComponent*>(gobj()), x, y, ((AtkCoordType)(coord_type)));
}

Glib::RefPtr<Atk::Object> Component::get_accessible_at_point(int x, int y, CoordType coord_type)
{
  return Glib::wrap(atk_component_ref_accessible_at_point(gobj(), x, y, ((AtkCoordType)(coord_type))));
}

void Component::get_extents(int& x, int& y, int& width, int& height, CoordType coord_type) const
{
  atk_component_get_extents(const_cast<AtkComponent*>(gobj()), &(x), &(y), &(width), &(height), ((AtkCoordType)(coord_type)));
}

#ifndef ATKMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
void Component::get_position(int& x, int& y, CoordType coord_type) const
{
  atk_component_get_position(const_cast<AtkComponent*>(gobj()), &(x), &(y), ((AtkCoordType)(coord_type)));
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // ATKMM_DISABLE_DEPRECATED

#ifndef ATKMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
void Component::get_size(int& width, int& height) const
{
  atk_component_get_size(const_cast<AtkComponent*>(gobj()), &(width), &(height));
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // ATKMM_DISABLE_DEPRECATED

Layer Component::get_layer() const
{
  return ((Layer)(atk_component_get_layer(const_cast<AtkComponent*>(gobj()))));
}

int Component::get_mdi_zorder() const
{
  return atk_component_get_mdi_zorder(const_cast<AtkComponent*>(gobj()));
}

bool Component::grab_focus()
{
  return atk_component_grab_focus(gobj());
}

#ifndef ATKMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
void Component::remove_focus_handler(guint handler_id)
{
  atk_component_remove_focus_handler(gobj(), handler_id);
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // ATKMM_DISABLE_DEPRECATED

bool Component::set_extents(int x, int y, int width, int height, CoordType coord_type)
{
  return atk_component_set_extents(gobj(), x, y, width, height, ((AtkCoordType)(coord_type)));
}

bool Component::set_position(int x, int y, CoordType coord_type)
{
  return atk_component_set_position(gobj(), x, y, ((AtkCoordType)(coord_type)));
}

bool Component::set_size(int width, int height)
{
  return atk_component_set_size(gobj(), width, height);
}


guint Atk::Component::add_focus_handler_vfunc(AtkFocusHandler handler) 
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->add_focus_handler)
  {
    guint retval((*base->add_focus_handler)(gobj(),handler));
    return retval;
  }

  typedef guint RType;
  return RType();
}
bool Atk::Component::contains_vfunc(int x, int y, CoordType coord_type) const
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->contains)
  {
    bool retval((*base->contains)(const_cast<AtkComponent*>(gobj()),x,y,((AtkCoordType)(coord_type))));
    return retval;
  }

  typedef bool RType;
  return RType();
}
Glib::RefPtr<Atk::Object> Atk::Component::get_accessible_at_point_vfunc(int x, int y, CoordType coord_type) 
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->ref_accessible_at_point)
  {
    Glib::RefPtr<Atk::Object> retval(Glib::wrap((*base->ref_accessible_at_point)(gobj(),x,y,((AtkCoordType)(coord_type)))));
    return retval;
  }

  typedef Glib::RefPtr<Atk::Object> RType;
  return RType();
}
void Atk::Component::get_extents_vfunc(int& x, int& y, int& width, int& height, CoordType coord_type) const
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->get_extents)
  {
    (*base->get_extents)(const_cast<AtkComponent*>(gobj()),&(x),&(y),&(width),&(height),((AtkCoordType)(coord_type)));
  }
}
void Atk::Component::get_position_vfunc(int& x, int& y, CoordType coord_type) const
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->get_position)
  {
    (*base->get_position)(const_cast<AtkComponent*>(gobj()),&(x),&(y),((AtkCoordType)(coord_type)));
  }
}
void Atk::Component::get_size_vfunc(int& width, int& height) const
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->get_size)
  {
    (*base->get_size)(const_cast<AtkComponent*>(gobj()),&(width),&(height));
  }
}
Layer Atk::Component::get_layer_vfunc() const
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->get_layer)
  {
    Layer retval(((Layer)((*base->get_layer)(const_cast<AtkComponent*>(gobj())))));
    return retval;
  }

  typedef Layer RType;
  return RType();
}
int Atk::Component::get_mdi_zorder_vfunc() const
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->get_mdi_zorder)
  {
    int retval((*base->get_mdi_zorder)(const_cast<AtkComponent*>(gobj())));
    return retval;
  }

  typedef int RType;
  return RType();
}
bool Atk::Component::grab_focus_vfunc() 
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->grab_focus)
  {
    bool retval((*base->grab_focus)(gobj()));
    return retval;
  }

  typedef bool RType;
  return RType();
}
void Atk::Component::remove_focus_handler_vfunc(guint handler_id) 
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->remove_focus_handler)
  {
    (*base->remove_focus_handler)(gobj(),handler_id);
  }
}
bool Atk::Component::set_extents_vfunc(int x, int y, int width, int height, CoordType coord_type) 
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->set_extents)
  {
    bool retval((*base->set_extents)(gobj(),x,y,width,height,((AtkCoordType)(coord_type))));
    return retval;
  }

  typedef bool RType;
  return RType();
}
bool Atk::Component::set_position_vfunc(int x, int y, CoordType coord_type) 
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->set_position)
  {
    bool retval((*base->set_position)(gobj(),x,y,((AtkCoordType)(coord_type))));
    return retval;
  }

  typedef bool RType;
  return RType();
}
bool Atk::Component::set_size_vfunc(int width, int height) 
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->set_size)
  {
    bool retval((*base->set_size)(gobj(),width,height));
    return retval;
  }

  typedef bool RType;
  return RType();
}


} // namespace Atk


