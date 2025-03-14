// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/cellview.h>
#include <gtkmm/private/cellview_p.h>


/*
 * Copyright 1998-2002 The gtkmm Development Team
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

#include <gtkmm/cellrenderertext.h>
#include <gtkmm/cellrendererpixbuf.h>
#include <gtk/gtk.h>

namespace Gtk
{

CellView::CellView(const Glib::ustring& text, bool use_markup)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Widget(Glib::ConstructParams(cellview_class_.init()))
{
  auto cell = Gtk::manage(new Gtk::CellRendererText());

  if(use_markup)
  {
    cell->property_markup() = text;
  }
  else
  {
    cell->property_text() = text;
  }

  pack_start(*cell);
}

CellView::CellView(const Glib::RefPtr<Gdk::Pixbuf>& pixbuf)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Widget(Glib::ConstructParams(cellview_class_.init()))
{
  auto cell = Gtk::manage(new Gtk::CellRendererPixbuf());

  cell->property_pixbuf() = pixbuf;

  pack_start(*cell);
}

void CellView::unset_model()
{
  gtk_cell_view_set_model(gobj(), 0);
}


} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

Gtk::CellView* wrap(GtkCellView* object, bool take_copy)
{
  return dynamic_cast<Gtk::CellView *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& CellView_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CellView_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_cell_view_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  CellLayout::add_interface(get_type());
  Orientable::add_interface(get_type());

  }

  return *this;
}


void CellView_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* CellView_Class::wrap_new(GObject* o)
{
  return manage(new CellView((GtkCellView*)(o)));

}


/* The implementation: */

CellView::CellView(const Glib::ConstructParams& construct_params)
:
  Gtk::Widget(construct_params)
{
  }

CellView::CellView(GtkCellView* castitem)
:
  Gtk::Widget((GtkWidget*)(castitem))
{
  }


CellView::CellView(CellView&& src) noexcept
: Gtk::Widget(std::move(src))
  , CellLayout(std::move(src))
  , Orientable(std::move(src))
{}

CellView& CellView::operator=(CellView&& src) noexcept
{
  Gtk::Widget::operator=(std::move(src));
  CellLayout::operator=(std::move(src));
  Orientable::operator=(std::move(src));
  return *this;
}

CellView::~CellView() noexcept
{
  destroy_();
}

CellView::CppClassType CellView::cellview_class_; // initialize static member

GType CellView::get_type()
{
  return cellview_class_.init().get_type();
}


GType CellView::get_base_type()
{
  return gtk_cell_view_get_type();
}


CellView::CellView()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Widget(Glib::ConstructParams(cellview_class_.init()))
{
  

}

void CellView::set_model(const Glib::RefPtr<TreeModel>& model)
{
  gtk_cell_view_set_model(gobj(), Glib::unwrap(model));
}

Glib::RefPtr<TreeModel> CellView::get_model()
{
  Glib::RefPtr<TreeModel> retvalue = Glib::wrap(gtk_cell_view_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const TreeModel> CellView::get_model() const
{
  return const_cast<CellView*>(this)->get_model();
}

void CellView::set_displayed_row(const TreeModel::Path& path)
{
  gtk_cell_view_set_displayed_row(gobj(), const_cast<GtkTreePath*>((path).gobj()));
}

TreeModel::Path CellView::get_displayed_row() const
{
  return Gtk::TreePath(gtk_cell_view_get_displayed_row(const_cast<GtkCellView*>(gobj())), false);
}

#ifndef GTKMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
void CellView::set_background_color(const Gdk::Color& color)
{
  gtk_cell_view_set_background_color(gobj(), (color).gobj());
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GTKMM_DISABLE_DEPRECATED

void CellView::set_background_rgba(const Gdk::RGBA& rgba)
{
  gtk_cell_view_set_background_rgba(gobj(), (rgba).gobj());
}

bool CellView::get_draw_sensitive() const
{
  return gtk_cell_view_get_draw_sensitive(const_cast<GtkCellView*>(gobj()));
}

void CellView::set_draw_sensitive(bool draw_sensitive)
{
  gtk_cell_view_set_draw_sensitive(gobj(), static_cast<int>(draw_sensitive));
}

bool CellView::get_fit_model() const
{
  return gtk_cell_view_get_fit_model(const_cast<GtkCellView*>(gobj()));
}

void CellView::set_fit_model(bool fit_model)
{
  gtk_cell_view_set_fit_model(gobj(), static_cast<int>(fit_model));
}


Glib::PropertyProxy_WriteOnly< Glib::ustring > CellView::property_background() 
{
  return Glib::PropertyProxy_WriteOnly< Glib::ustring >(this, "background");
}

#ifndef GTKMM_DISABLE_DEPRECATED

Glib::PropertyProxy< Gdk::Color > CellView::property_background_gdk() 
{
  return Glib::PropertyProxy< Gdk::Color >(this, "background-gdk");
}
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

Glib::PropertyProxy_ReadOnly< Gdk::Color > CellView::property_background_gdk() const
{
  return Glib::PropertyProxy_ReadOnly< Gdk::Color >(this, "background-gdk");
}
#endif // GTKMM_DISABLE_DEPRECATED


Glib::PropertyProxy< Gdk::RGBA > CellView::property_background_rgba() 
{
  return Glib::PropertyProxy< Gdk::RGBA >(this, "background-rgba");
}

Glib::PropertyProxy_ReadOnly< Gdk::RGBA > CellView::property_background_rgba() const
{
  return Glib::PropertyProxy_ReadOnly< Gdk::RGBA >(this, "background-rgba");
}

Glib::PropertyProxy< bool > CellView::property_background_set() 
{
  return Glib::PropertyProxy< bool >(this, "background-set");
}

Glib::PropertyProxy_ReadOnly< bool > CellView::property_background_set() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "background-set");
}

Glib::PropertyProxy< Glib::RefPtr<TreeModel> > CellView::property_model() 
{
  return Glib::PropertyProxy< Glib::RefPtr<TreeModel> >(this, "model");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> > CellView::property_model() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> >(this, "model");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellArea> > CellView::property_cell_area() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellArea> >(this, "cell-area");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellAreaContext> > CellView::property_cell_area_context() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellAreaContext> >(this, "cell-area-context");
}

Glib::PropertyProxy< bool > CellView::property_draw_sensitive() 
{
  return Glib::PropertyProxy< bool >(this, "draw-sensitive");
}

Glib::PropertyProxy_ReadOnly< bool > CellView::property_draw_sensitive() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "draw-sensitive");
}

Glib::PropertyProxy< bool > CellView::property_fit_model() 
{
  return Glib::PropertyProxy< bool >(this, "fit-model");
}

Glib::PropertyProxy_ReadOnly< bool > CellView::property_fit_model() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "fit-model");
}


} // namespace Gtk


