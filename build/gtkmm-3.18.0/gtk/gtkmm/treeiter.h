// -*- c++ -*-
// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!
#ifndef _GTKMM_TREEITER_H
#define _GTKMM_TREEITER_H

#include <gtkmmconfig.h>


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright(C) 1998-2002 The gtkmm Development Team
 *
 * This library is free software, ) you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, ) either
 * version 2.1 of the License, or(at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY, ) without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library, ) if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */


#include <gtkmm/treemodelcolumn.h>
#include <iterator>
#include <gtk/gtk.h> /* for GtkTreeIter */
#ifdef GLIBMM_HAVE_SUN_REVERSE_ITERATOR
#include <cstddef> /* for std::ptrdiff_t */
#endif

namespace Gtk
{

class TreeModel;
class TreeRow;
class TreeNodeChildren;

/**
 * @ingroup TreeView
 */
class TreeIterBase
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef TreeIterBase CppObjectType;
  typedef GtkTreeIter BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  TreeIterBase(const TreeIterBase& other) noexcept;
  TreeIterBase& operator=(const TreeIterBase& other) noexcept;

  TreeIterBase(TreeIterBase&& other) noexcept;
  TreeIterBase& operator=(TreeIterBase&& other) noexcept;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type() G_GNUC_CONST;

  TreeIterBase();

  explicit TreeIterBase(const GtkTreeIter* gobject); // always takes a copy

  ///Provides access to the underlying C instance.
  GtkTreeIter*       gobj()       { return &gobject_; }

  ///Provides access to the underlying C instance.
  const GtkTreeIter* gobj() const { return &gobject_; }

protected:
  GtkTreeIter gobject_;

private:
  
  
  //A wrap() for TreeIterBase* wouldn't be very helpful.


};


// In order to offer STL-like iterator functionality, we cannot wrap
// GtkTreeIter directly.  Most GTK+ functions that operate on GtkTreeIter
// are virtual functions in GtkTreeModel.  Therefore, the C++ TreeIter
// must store a pointer to the Gtk::TreeModel to which it belongs.
//
// Another problem, which is much worse, is that the GTK+ tree iterator
// doesn't support the STL-style half-open interval [begin,end).  Instead,
// it uses a [first,last] interval, and functions return FALSE to indicate
// the end was reached.  Also, some functions accept a NULL GtkTreeIter*,
// which will be interpreted as the end() iterator.
//
// Most of the immense complexity in the Gtk::TreeIter implementation is
// needed for proper emulation of [begin,end) intervals.  Unfortunately,
// it's not even possible to encapsulate everything in the TreeIter
// class.  Almost all wrapper methods dealing with GtkTreeIter must be
// carefully implemented by hand.  TODO: document implementation details

//TODO: Implement a const_iterator too:
//danielk says that this ConstTreeIter class should return a ConstTreeRow, which would not allow operator=.

/** A Gtk::TreeModel::iterator is a reference to a specific node on a specific
 * model.
 *
 * It is a generic structure with an integer and three generic pointers.
 * These are filled in by the model in a model-specific way.
 *
 * One can convert a path to an iterator by calling Gtk::TreeModel::get_iter().
 *
 * These iterators are the primary way of accessing a model and are similar to the iterators
 * used by Gtk::TextBuffer. The model interface defines a set of operations
 * using them for navigating the model.
 *
 * The lifecycle of an iterator can be a little confusing at first. Iterators
 * are expected to always be valid for as long as the model is unchanged (and
 * doesn't emit a signal).
 * Additionally, some models guarantee that an iterator is valid for as
 * long as the node it refers to is valid (most notably the Gtk::TreeStore and
 * Gtk::ListStore).
 *
 * Although generally uninteresting, as one always has to
 * allow for the case where iterators do not persist beyond a signal, some very
 * important performance enhancements were made in the sort model. As a result,
 * the Gtk::TREE_MODEL_ITERS_PERSIST flag was added to indicate this behaviour -
 * see Gtk::TreeModel::get_flags().
 *
 * Typedefed as Gtk::TreeModel::iterator.
 * The Gtk::TreeModel iterator.
 * @ingroup TreeView
 */
class TreeIter : public TreeIterBase
{
public:
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef Gtk::TreeRow              value_type;
  typedef int                       difference_type;
  typedef const Gtk::TreeRow&       reference;
  typedef const Gtk::TreeRow*       pointer;

  TreeIter();

  TreeIter&      operator++();
  const TreeIter operator++(int);

  /** Please note that this is very slow compared to operator++().
   */
  TreeIter&      operator--();

  /** Please note that this is very slow compared to operator++().
   */
  const TreeIter operator--(int);

  inline reference operator*()  const;
  inline pointer   operator->() const;

  bool equal(const TreeIter& other) const;

  /** This typedef is just to make it more obvious that
   * our operator const void* should be used like operator bool().
   */
  typedef const void* BoolExpr;

  /** Discover whether the iterator is valid, and not equal to end().
   * For instance,
   * @code
   * if(treeiter)
   *   do_something()
   * @endcode
   */
  operator BoolExpr() const;

  /** This is only useful when implementing a custom Gtk::TreeModel class.
   * Compare the iterator's stamp with your model's stamp to discover whether it is valid.
   * @see set_stamp().
   * @result The iterator's stamp.
   */
  int get_stamp() const;

  /** This is only useful when implementing a custom Gtk::TreeModel class.
   * Set the stamp to be equal to your model's stamp, to mark the iterator as valid.
   * When your model's structure changes, you should increment your model's stamp
   * to mark all older iterators as invalid. They will be recognised as invalid because
   * they will then have an incorrect stamp.
   */
  void set_stamp(int stamp);

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  explicit TreeIter(TreeModel* model); // used in TreeModel methods
  TreeIter(GtkTreeModel* model, const GtkTreeIter* iter); // used by signal proxies

  void set_model_refptr(const Glib::RefPtr<TreeModel>& model);
  void set_model_gobject(GtkTreeModel* model);
  GtkTreeModel* get_model_gobject() const;

  void setup_end_iterator(const TreeIter& last_valid);

  const GtkTreeIter* get_gobject_if_not_end() const
    { return (!is_end_) ? &gobject_ : 0; }

  const GtkTreeIter* get_parent_gobject_if_end() const
    { return (is_end_ && gobject_.stamp) ? &gobject_ : 0; }

protected:

  // Yes, using a simple TreeModel* rather than Glib::RefPtr<TreeModel>
  // violates the general policy.  But Gtk::TreeIter should have a trivial
  // copy constructor and assignment operator, i.e. it must contain only
  // POD (plain old data).
  //
  // Gtk::TreeIter is copied a lot, particularly often as return value from
  // methods.  Postfix ++ must return by value, and STL algorithms usually
  // pass iterators by value, too.  With a RefPtr<> as member data, copying
  // would no longer be trivial, and even cause frequent calls to reference()
  // and unreference().  That usually doesn't matter much for GUI stuff, but
  // Gtk::TreeModel is used as a generic container.  Imagine a for-loop that
  // checks whether iter != children.end() on each iteration.

  TreeModel* model_;
  bool       is_end_;

  friend class Gtk::TreeRow;
  friend class Gtk::TreeNodeChildren;
  friend class Gtk::TreeModel;

#endif // DOXYGEN_SHOULD_SKIP_THIS
};

/** @relates Gtk::TreeIter */
inline bool operator==(const TreeIter& lhs, const TreeIter& rhs)
  { return lhs.equal(rhs); }

/** @relates Gtk::TreeIter */
inline bool operator!=(const TreeIter& lhs, const TreeIter& rhs)
  { return !lhs.equal(rhs); }


template <class ColumnType>
class TreeValueProxy
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  inline TreeValueProxy(const TreeRow& row, const TreeModelColumn<ColumnType>& column);
#endif

  inline TreeValueProxy<ColumnType>& operator=(const ColumnType& data);
  inline operator ColumnType() const;

private:
  const TreeRow&                      row_;
  const TreeModelColumn<ColumnType>&  column_;

  // no copy assignment
  TreeValueProxy<ColumnType>& operator=(const TreeValueProxy<ColumnType>&);
};


/** Typedefed as TreeModel::Row.
 *
 * Dereference a TreeModel::iterator to get the Row. Use operator[] or set_value() and get_value() to access the
 * values in the columns of this row.
 *
 * If the model contains a hierarchy of rows (such as Gtk::TreeStore), then you can access the child rows with
 * children().
 *
 * You can use a const TreeModel::Row& for any parameter that takes a const TreeModel::iterator&.
 * @ingroup TreeView
 */
class TreeRow : public TreeIter //We use public inheritance so that we can cast from a TreeRow to a TreeIter.
{
public:

  /** Use this to set and get the value of this @a column of this row.
   * This is a templated method, so the compiler will not allow you to provide an inappropriate type
   * of data for the model column.
   *
   * This is just a more convenient syntax that does the same thing as set_value() and get_value().
   *
   * @param column The model column..
   */
  template <class ColumnType> inline
  TreeValueProxy<ColumnType> operator[](const TreeModelColumn<ColumnType>& column) const;

  /** Sets the value of this @a column of this row.
   * This is a templated method, so the compiler will not allow you to provide an inappropriate type
   * of @a data for the model column.
   *
   * See also operator[].
   *
   * @param column The model column.
   * @param data The new value to use for this column of this row.
   */
  template <class ColumnType>
  void set_value(const TreeModelColumn<ColumnType>& column, const ColumnType& data) const;

  /** Use set_value(const TreeModelColumn<>& column, const ColumnType& data) unless
   * you do not know the column type at compile-time.
   * If the @a data is of an inappropriate C++ type then this might fail at runtime.
   * @param column The number of the column whose value you want to change.
   * @param data The new value to use for this column of this row.
   */
  template <class ColumnType>
  void set_value(int column, const ColumnType& data) const;

  /** Gets the value of this @a column of this row.
   * This is a templated method, so the compiler will not allow you to provide an inappropriate type
   * of data for the model column.
   *
   * See also operator[].
   *
   * @param column The model column.
   * @result The value of this column of this row
   */
  template <class ColumnType>
  ColumnType get_value(const TreeModelColumn<ColumnType>& column) const;

  /** Use get_value(const TreeModelColumn<>& column) unless
   * you do not know the column type at compile-time.
   * If the @a data output argument is of an inappropriate C++ type then this might fail at runtime.
   * @param column The number of the column whose value you want to query.
   * @param[out] data An output argument which will contain the value of this column of this row.
   */
  template <class ColumnType>
  void get_value(int column, ColumnType& data) const;

  /** This returns an STL-like container API, for iterating over the rows.
   * See also Gtk::TreeModel::children() for the top-level children.
   */
  const TreeNodeChildren& children() const;

  /** Gets an iterator to the parent row of this row.
   * @result An iterator to the parent row.
   */
  TreeIter parent() const;

  /** This typedef is just to make it more obvious that
   * our operator const void* should be used like operator bool().
   */
  typedef const void* BoolExpr;

  /** Discover whether this is a valid row.
   * For instance,
   * @code
   * if(treeiter)
   *   do_something()
   * @endcode
   */
  operator BoolExpr() const;

  /// Provides access to the underlying C GObject.
  GtkTreeIter*       gobj()       { return TreeIter::gobj(); }

  /// Provides access to the underlying C GObject.
  const GtkTreeIter* gobj() const { return TreeIter::gobj(); }

private:
  // Forwarders to Gtk::TreeModel virtual methods.
  void set_value_impl(int column, const Glib::ValueBase& value) const;
  void get_value_impl(int column, Glib::ValueBase& value) const;
};


//TODO: Document begin(), end(), size(), etc, in an STL-style way. murrayc.

/** typedefed as TreeModel::Children.
 * Virtual container of TreeModel::Row items.
 * @ingroup TreeView
 */
class TreeNodeChildren : public TreeIter
{
public:
  typedef Gtk::TreeRow  value_type;
  typedef unsigned int  size_type;
  typedef int           difference_type;
  typedef Gtk::TreeIter iterator;

  #ifndef GLIBMM_HAVE_SUN_REVERSE_ITERATOR
    typedef std::reverse_iterator<iterator> reverse_iterator;
  #else
    typedef std::reverse_iterator<iterator, std::random_access_iterator_tag,
                                  int, int&, int*, std::ptrdiff_t> reverse_iterator;
  #endif

    typedef Gtk::TreeIter const_iterator; //TODO: Make it a real const_iterator.

  #ifndef GLIBMM_HAVE_SUN_REVERSE_ITERATOR
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
  #else
    typedef std::reverse_iterator<const_iterator, std::random_access_iterator_tag,
                                  int, const int&, const int*, std::ptrdiff_t> const_reverse_iterator;
  #endif

  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end()   const;

  // Note: there is no advantage in not inlining these methods.
  // We can't change them without breaking ABI anyway.
  reverse_iterator       rbegin()       { return reverse_iterator(end());         }
  reverse_iterator       rend()         { return reverse_iterator(begin());       }
  const_reverse_iterator rbegin() const { return const_reverse_iterator(end());   }
  const_reverse_iterator rend()   const { return const_reverse_iterator(begin()); }

  value_type operator[](size_type index) const;

  size_type size() const;
  bool empty() const;

  /** This typedef is just to make it more obvious that
   * our operator const void* should be used like operator bool().
   */
  typedef const void* BoolExpr;

  /** Discover whether this is a valid TreeNodeChildren.
   * For instance,
   * @code
   * if(children)
   *   do_something()
   * @endcode
   */
  operator BoolExpr() const
  {
    return !empty() ? GINT_TO_POINTER(1) : 0;
  }

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  explicit TreeNodeChildren(TreeModel* model)
    : TreeIter(model) {}

  const GtkTreeIter* get_parent_gobject() const
    { return (gobject_.stamp != 0) ? &gobject_ : 0; }

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
};


#ifndef DOXYGEN_SHOULD_SKIP_THIS

/**** Gtk::TreeIter ********************************************************/

inline
TreeIter::reference TreeIter::operator*() const
{
  return static_cast<const TreeRow&>(*this);
}

inline
TreeIter::pointer TreeIter::operator->() const
{
  return static_cast<const TreeRow*>(this);
}


/**** Gtk::TreeValueProxy<> ************************************************/

template <class ColumnType> inline
TreeValueProxy<ColumnType>::TreeValueProxy(const TreeRow& row, const TreeModelColumn<ColumnType>& column)
:
  row_    (row),
  column_ (column)
{}

template <class ColumnType> inline
TreeValueProxy<ColumnType>& TreeValueProxy<ColumnType>::operator=(const ColumnType& data)
{
  row_.set_value(column_, data);
  return *this;
}

template <class ColumnType> inline
TreeValueProxy<ColumnType>::operator ColumnType() const
{
  return row_.get_value(column_);
}


/**** Gtk::TreeRow *********************************************************/

template <class ColumnType> inline
TreeValueProxy<ColumnType> TreeRow::operator[](const TreeModelColumn<ColumnType>& column) const
{
  return TreeValueProxy<ColumnType>(*this, column);
}

template <class ColumnType>
void TreeRow::set_value(const TreeModelColumn<ColumnType>& column, const ColumnType& data) const
{
  typedef typename Gtk::TreeModelColumn<ColumnType>::ValueType ValueType;

  ValueType value;
  value.init(column.type());

  value.set(data);
  this->set_value_impl(column.index(), value);
}

template <class ColumnType>
void TreeRow::set_value(int column, const ColumnType& data) const
{
  //This could fail at run-time, because the wrong ColumnType might be used.
  //It's only for dynamically generated model columns.

  typedef typename Gtk::TreeModelColumn<ColumnType> type_cppcolumn;
  typedef typename type_cppcolumn::ValueType ValueType;

  ValueType value;
  value.init(ValueType::value_type());

  value.set(data);
  this->set_value_impl(column, value);
}

template <class ColumnType>
ColumnType TreeRow::get_value(const TreeModelColumn<ColumnType>& column) const
{
  typedef typename Gtk::TreeModelColumn<ColumnType>::ValueType ValueType;

  ValueType value;
  this->get_value_impl(column.index(), value);

  return value.get();
}

template <class ColumnType>
void TreeRow::get_value(int column, ColumnType& data) const
{
  //This could fail at run-time, because the wrong ColumnType might be used.
  //It's only for dynamically generated model columns.

  typedef typename Gtk::TreeModelColumn<ColumnType>::ValueType ValueType;

  ValueType value;
  this->get_value_impl(column, value);

  data = value.get();
}

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Gtk


namespace Glib
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class Value<Gtk::TreeIterBase> : public Glib::Value_Boxed<Gtk::TreeIterBase>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GTKMM_TREEITER_H */

