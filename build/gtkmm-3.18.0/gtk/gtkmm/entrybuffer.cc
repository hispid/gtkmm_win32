// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/entrybuffer.h>
#include <gtkmm/private/entrybuffer_p.h>


/* Copyright(C) 1998-2002 The gtkmm Development Team
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

#include <gtk/gtk.h>
#include <glib.h>


namespace Gtk
{

EntryBuffer::EntryBuffer(const Glib::ustring& text)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(entrybuffer_class_.init()))
{
  set_text(text);
}

void EntryBuffer::set_text(const Glib::ustring& text)
{
  gtk_entry_buffer_set_text(gobj(), text.c_str(), -1 /* see docs */);
}

guint EntryBuffer::insert_text(guint position, const Glib::ustring& text)
{
  return gtk_entry_buffer_insert_text(gobj(), position, text.c_str(), -1 /* see docs */);
}

void EntryBuffer::emit_inserted_text(guint position, const Glib::ustring& text)
{
  gtk_entry_buffer_emit_inserted_text(gobj(), position, text.c_str(), -1 /* see docs */);
}

} // namespace Gtk

namespace
{


static void EntryBuffer_signal_inserted_text_callback(GtkEntryBuffer* self, guint p0,const gchar* p1,guint p2,void* data)
{
  using namespace Gtk;
  typedef sigc::slot< void,guint,const gchar*,guint > SlotType;

  auto obj = dynamic_cast<EntryBuffer*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0, p1, p2);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

static const Glib::SignalProxyInfo EntryBuffer_signal_inserted_text_info =
{
  "inserted-text",
  (GCallback) &EntryBuffer_signal_inserted_text_callback,
  (GCallback) &EntryBuffer_signal_inserted_text_callback
};


static void EntryBuffer_signal_deleted_text_callback(GtkEntryBuffer* self, guint p0,guint p1,void* data)
{
  using namespace Gtk;
  typedef sigc::slot< void,guint,guint > SlotType;

  auto obj = dynamic_cast<EntryBuffer*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0, p1);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

static const Glib::SignalProxyInfo EntryBuffer_signal_deleted_text_info =
{
  "deleted-text",
  (GCallback) &EntryBuffer_signal_deleted_text_callback,
  (GCallback) &EntryBuffer_signal_deleted_text_callback
};


} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gtk::EntryBuffer> wrap(GtkEntryBuffer* object, bool take_copy)
{
  return Glib::RefPtr<Gtk::EntryBuffer>( dynamic_cast<Gtk::EntryBuffer*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& EntryBuffer_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &EntryBuffer_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_entry_buffer_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void EntryBuffer_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->inserted_text = &inserted_text_callback;
  klass->deleted_text = &deleted_text_callback;
}


void EntryBuffer_Class::inserted_text_callback(GtkEntryBuffer* self, guint p0, const gchar* p1, guint p2)
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
        obj->on_inserted_text(p0, p1, p2);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->inserted_text)
    (*base->inserted_text)(self, p0, p1, p2);
}
void EntryBuffer_Class::deleted_text_callback(GtkEntryBuffer* self, guint p0, guint p1)
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
        obj->on_deleted_text(p0, p1);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->deleted_text)
    (*base->deleted_text)(self, p0, p1);
}


Glib::ObjectBase* EntryBuffer_Class::wrap_new(GObject* object)
{
  return new EntryBuffer((GtkEntryBuffer*)object);
}


/* The implementation: */

GtkEntryBuffer* EntryBuffer::gobj_copy()
{
  reference();
  return gobj();
}

EntryBuffer::EntryBuffer(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

EntryBuffer::EntryBuffer(GtkEntryBuffer* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


EntryBuffer::EntryBuffer(EntryBuffer&& src) noexcept
: Glib::Object(std::move(src))
{}

EntryBuffer& EntryBuffer::operator=(EntryBuffer&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  return *this;
}

EntryBuffer::~EntryBuffer() noexcept
{}


EntryBuffer::CppClassType EntryBuffer::entrybuffer_class_; // initialize static member

GType EntryBuffer::get_type()
{
  return entrybuffer_class_.init().get_type();
}


GType EntryBuffer::get_base_type()
{
  return gtk_entry_buffer_get_type();
}


EntryBuffer::EntryBuffer()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(entrybuffer_class_.init()))
{
  

}

Glib::RefPtr<EntryBuffer> EntryBuffer::create()
{
  return Glib::RefPtr<EntryBuffer>( new EntryBuffer() );
}

Glib::RefPtr<EntryBuffer> EntryBuffer::create(const Glib::ustring& text)
{
  return Glib::RefPtr<EntryBuffer>( new EntryBuffer(text) );
}

gsize EntryBuffer::get_bytes() const
{
  return gtk_entry_buffer_get_bytes(const_cast<GtkEntryBuffer*>(gobj()));
}

guint EntryBuffer::get_length() const
{
  return gtk_entry_buffer_get_length(const_cast<GtkEntryBuffer*>(gobj()));
}

Glib::ustring EntryBuffer::get_text() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_entry_buffer_get_text(const_cast<GtkEntryBuffer*>(gobj())));
}

void EntryBuffer::set_max_length(int max_length)
{
  gtk_entry_buffer_set_max_length(gobj(), max_length);
}

int EntryBuffer::get_max_length() const
{
  return gtk_entry_buffer_get_max_length(const_cast<GtkEntryBuffer*>(gobj()));
}

guint EntryBuffer::delete_text(guint position, int n_chars)
{
  return gtk_entry_buffer_delete_text(gobj(), position, n_chars);
}

void EntryBuffer::emit_deleted_text(guint position, guint n_chars)
{
  gtk_entry_buffer_emit_deleted_text(gobj(), position, n_chars);
}


Glib::SignalProxy3< void,guint,const gchar*,guint > EntryBuffer::signal_inserted_text()
{
  return Glib::SignalProxy3< void,guint,const gchar*,guint >(this, &EntryBuffer_signal_inserted_text_info);
}


Glib::SignalProxy2< void,guint,guint > EntryBuffer::signal_deleted_text()
{
  return Glib::SignalProxy2< void,guint,guint >(this, &EntryBuffer_signal_deleted_text_info);
}


Glib::PropertyProxy< Glib::ustring > EntryBuffer::property_text() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "text");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > EntryBuffer::property_text() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "text");
}

Glib::PropertyProxy_ReadOnly< guint > EntryBuffer::property_length() const
{
  return Glib::PropertyProxy_ReadOnly< guint >(this, "length");
}

Glib::PropertyProxy< int > EntryBuffer::property_max_length() 
{
  return Glib::PropertyProxy< int >(this, "max-length");
}

Glib::PropertyProxy_ReadOnly< int > EntryBuffer::property_max_length() const
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "max-length");
}


void Gtk::EntryBuffer::on_inserted_text(guint position, const gchar* chars, guint n_chars)
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->inserted_text)
    (*base->inserted_text)(gobj(),position,chars,n_chars);
}
void Gtk::EntryBuffer::on_deleted_text(guint position, guint n_chars)
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->deleted_text)
    (*base->deleted_text)(gobj(),position,n_chars);
}


} // namespace Gtk


