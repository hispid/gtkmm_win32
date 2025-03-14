// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/treestore.h>
#include <gtkmm/private/treestore_p.h>


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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <glibmm/vectorutils.h>

#include <gtk/gtk.h>


namespace Gtk
{

TreeStore::TreeStore(const TreeModelColumnRecord& columns)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(treestore_class_.init()))
{
  gtk_tree_store_set_column_types(gobj(), columns.size(), const_cast<GType*>(columns.types()));
}

void TreeStore::set_column_types(const TreeModelColumnRecord& columns)
{
   gtk_tree_store_set_column_types(gobj(), columns.size(), const_cast<GType*>(columns.types()));
}

TreeModel::iterator TreeStore::erase(const iterator& iter)
{
  g_assert(iter.get_gobject_if_not_end() != 0);

  iterator next (iter);
  ++next;

  auto tmp = *iter.gobj();
  gtk_tree_store_remove(gobj(), &tmp);

  return next;
}

TreeModel::iterator TreeStore::insert(const iterator& iter)
{
  iterator new_pos (this);

  gtk_tree_store_insert_before(
      gobj(), new_pos.gobj(),
      const_cast<GtkTreeIter*>(iter.get_parent_gobject_if_end()),
      const_cast<GtkTreeIter*>(iter.get_gobject_if_not_end()));

  if(new_pos.gobj()->stamp == 0)
    new_pos.setup_end_iterator(iter);

  return new_pos;
}

TreeModel::iterator TreeStore::insert_after(const iterator& iter)
{
  iterator new_pos (this);

  gtk_tree_store_insert_after(
      gobj(), new_pos.gobj(),
      const_cast<GtkTreeIter*>(iter.get_parent_gobject_if_end()),
      const_cast<GtkTreeIter*>(iter.get_gobject_if_not_end()));

  if(new_pos.gobj()->stamp == 0)
    new_pos.setup_end_iterator(iter);

  return new_pos;
}

TreeModel::iterator TreeStore::prepend()
{
  iterator new_pos (this);
  gtk_tree_store_prepend(gobj(), new_pos.gobj(), 0);
  return new_pos;
}

TreeModel::iterator TreeStore::prepend(const TreeNodeChildren& node)
{
  iterator new_pos (this);

  gtk_tree_store_prepend(
      gobj(), new_pos.gobj(),
      const_cast<GtkTreeIter*>(node.get_parent_gobject()));

  return new_pos;
}

TreeModel::iterator TreeStore::append()
{
  iterator new_pos (this);
  gtk_tree_store_append(gobj(), new_pos.gobj(), 0);
  return new_pos;
}

TreeModel::iterator TreeStore::append(const TreeNodeChildren& node)
{
  iterator new_pos (this);

  gtk_tree_store_append(
      gobj(), new_pos.gobj(),
      const_cast<GtkTreeIter*>(node.get_parent_gobject()));

  return new_pos;
}

void TreeStore::move(const iterator& source, const iterator& destination)
{
  gtk_tree_store_move_before(gobj(),
      const_cast<GtkTreeIter*>(source.get_gobject_if_not_end()),
      const_cast<GtkTreeIter*>(destination.get_gobject_if_not_end()));
}

void TreeStore::reorder(const TreeNodeChildren& node, const std::vector<int>& new_order)
{
  gtk_tree_store_reorder(gobj(),
      const_cast<GtkTreeIter*>(node.get_parent_gobject()),
      const_cast<int*>(Glib::ArrayHandler<int>::vector_to_array(new_order).data ()));
}

void TreeStore::set_value_impl(const iterator& row, int column, const Glib::ValueBase& value)
{
  gtk_tree_store_set_value(
      gobj(), const_cast<GtkTreeIter*>(row.gobj()),
      column, const_cast<GValue*>(value.gobj()));
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gtk::TreeStore> wrap(GtkTreeStore* object, bool take_copy)
{
  return Glib::RefPtr<Gtk::TreeStore>( dynamic_cast<Gtk::TreeStore*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& TreeStore_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &TreeStore_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_tree_store_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  TreeModel::add_interface(get_type());
  TreeSortable::add_interface(get_type());
  TreeDragSource::add_interface(get_type());
  TreeDragDest::add_interface(get_type());
  Buildable::add_interface(get_type());

  }

  return *this;
}


void TreeStore_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* TreeStore_Class::wrap_new(GObject* object)
{
  return new TreeStore((GtkTreeStore*)object);
}


/* The implementation: */

GtkTreeStore* TreeStore::gobj_copy()
{
  reference();
  return gobj();
}

TreeStore::TreeStore(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

TreeStore::TreeStore(GtkTreeStore* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


TreeStore::TreeStore(TreeStore&& src) noexcept
: Glib::Object(std::move(src))
  , TreeModel(std::move(src))
  , TreeSortable(std::move(src))
  , TreeDragSource(std::move(src))
  , TreeDragDest(std::move(src))
  , Buildable(std::move(src))
{}

TreeStore& TreeStore::operator=(TreeStore&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  TreeModel::operator=(std::move(src));
  TreeSortable::operator=(std::move(src));
  TreeDragSource::operator=(std::move(src));
  TreeDragDest::operator=(std::move(src));
  Buildable::operator=(std::move(src));
  return *this;
}

TreeStore::~TreeStore() noexcept
{}


TreeStore::CppClassType TreeStore::treestore_class_; // initialize static member

GType TreeStore::get_type()
{
  return treestore_class_.init().get_type();
}


GType TreeStore::get_base_type()
{
  return gtk_tree_store_get_type();
}


TreeStore::TreeStore()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(treestore_class_.init()))
{
  

}

Glib::RefPtr<TreeStore> TreeStore::create(const TreeModelColumnRecord& columns)
{
  return Glib::RefPtr<TreeStore>( new TreeStore(columns) );
}

void TreeStore::iter_swap(const iterator& a, const iterator& b)
{
  gtk_tree_store_swap(gobj(), const_cast<GtkTreeIter*>((a).gobj()), const_cast<GtkTreeIter*>((b).gobj()));
}

void TreeStore::clear()
{
  gtk_tree_store_clear(gobj());
}

bool TreeStore::is_ancestor(const iterator& iter, const iterator& descendant) const
{
  return gtk_tree_store_is_ancestor(const_cast<GtkTreeStore*>(gobj()), const_cast<GtkTreeIter*>((iter).gobj()), const_cast<GtkTreeIter*>((descendant).gobj()));
}

int TreeStore::iter_depth(const iterator& iter) const
{
  return gtk_tree_store_iter_depth(const_cast<GtkTreeStore*>(gobj()), const_cast<GtkTreeIter*>((iter).gobj()));
}

bool TreeStore::iter_is_valid(const iterator& iter) const
{
  return gtk_tree_store_iter_is_valid(const_cast<GtkTreeStore*>(gobj()), const_cast<GtkTreeIter*>((iter).gobj()));
}


} // namespace Gtk


