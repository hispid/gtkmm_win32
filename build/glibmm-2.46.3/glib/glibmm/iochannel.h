// -*- c++ -*-
// Generated by gmmproc 2.46.3 -- DO NOT MODIFY!
#ifndef _GLIBMM_IOCHANNEL_H
#define _GLIBMM_IOCHANNEL_H


/* Copyright (C) 2002 The gtkmm Development Team
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


#include <glibmmconfig.h>
#include <glib.h> //For the GIOChannel enum values.
#include <glibmm/error.h>
#include <glibmm/refptr.h>
#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>
#include <string>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GIOChannel GIOChannel; }
#endif

namespace Glib
{

class Source;
class IOSource;

/** @addtogroup glibmmEnums glibmm Enums and Flags */

/** 
 *  @var SeekType SEEK_TYPE_CUR
 * The current position in the file.
 * 
 *  @var SeekType SEEK_TYPE_SET
 * The start of the file.
 * 
 *  @var SeekType SEEK_TYPE_END
 * The end of the file.
 * 
 *  @enum SeekType
 * 
 * An enumeration specifying the base position for a
 * g_io_channel_seek_position() operation.
 *
 * @ingroup glibmmEnums
 */
enum SeekType
{
  SEEK_TYPE_CUR,
  SEEK_TYPE_SET,
  SEEK_TYPE_END
};


/** 
 *  @var IOStatus IO_STATUS_ERROR
 * An error occurred.
 * 
 *  @var IOStatus IO_STATUS_NORMAL
 * Success.
 * 
 *  @var IOStatus IO_STATUS_EOF
 * End of file.
 * 
 *  @var IOStatus IO_STATUS_AGAIN
 * Resource temporarily unavailable.
 * 
 *  @enum IOStatus
 * 
 * Stati returned by most of the IOFuncs functions.
 *
 * @ingroup glibmmEnums
 */
enum IOStatus
{
  IO_STATUS_ERROR,
  IO_STATUS_NORMAL,
  IO_STATUS_EOF,
  IO_STATUS_AGAIN
};


/** 
 *  @var IOFlags IO_FLAG_APPEND
 * Turns on append mode, corresponds to O_APPEND
 * (see the documentation of the UNIX open() syscall).
 * 
 *  @var IOFlags IO_FLAG_NONBLOCK
 * Turns on nonblocking mode, corresponds to
 * O_NONBLOCK/O_NDELAY (see the documentation of the UNIX open()
 * syscall).
 * 
 *  @var IOFlags IO_FLAG_IS_READABLE
 * Indicates that the io channel is readable.
 * This flag cannot be changed.
 * 
 *  @var IOFlags IO_FLAG_IS_WRITABLE
 * Indicates that the io channel is writable.
 * This flag cannot be changed.
 * 
 *  @var IOFlags IO_FLAG_IS_WRITEABLE
 * A misspelled version of @a G_IO_FLAG_IS_WRITABLE
 * that existed before the spelling was fixed in GLib 2.30. It is kept
 * here for compatibility reasons. Deprecated since 2.30.
 * 
 *  @var IOFlags IO_FLAG_IS_SEEKABLE
 * Indicates that the io channel is seekable,
 * i.e. that g_io_channel_seek_position() can be used on it.
 * This flag cannot be changed.
 * 
 *  @var IOFlags IO_FLAG_MASK
 * The mask that specifies all the valid flags.
 * 
 *  @var IOFlags IO_FLAG_GET_MASK
 * The mask of the flags that are returned from
 * g_io_channel_get_flags().
 * 
 *  @var IOFlags IO_FLAG_SET_MASK
 * The mask of the flags that the user can modify
 * with g_io_channel_set_flags().
 * 
 *  @enum IOFlags
 * 
 * Specifies properties of a IOChannel. Some of the flags can only be
 * read with g_io_channel_get_flags(), but not changed with
 * g_io_channel_set_flags().
 *
 * @ingroup glibmmEnums
 * @par Bitwise operators:
 * <tt>%IOFlags operator|(IOFlags, IOFlags)</tt><br>
 * <tt>%IOFlags operator&(IOFlags, IOFlags)</tt><br>
 * <tt>%IOFlags operator^(IOFlags, IOFlags)</tt><br>
 * <tt>%IOFlags operator~(IOFlags)</tt><br>
 * <tt>%IOFlags& operator|=(IOFlags&, IOFlags)</tt><br>
 * <tt>%IOFlags& operator&=(IOFlags&, IOFlags)</tt><br>
 * <tt>%IOFlags& operator^=(IOFlags&, IOFlags)</tt><br>
 */
enum IOFlags
{
  IO_FLAG_APPEND = 1 << 0,
  IO_FLAG_NONBLOCK = 1 << 1,
  IO_FLAG_IS_READABLE = 1 << 2,
  IO_FLAG_IS_WRITABLE = 1 << 3,
  IO_FLAG_IS_WRITEABLE = 1 << 3,
  IO_FLAG_IS_SEEKABLE = 1 << 4,
  IO_FLAG_MASK = (1 << 5) - 1,
  IO_FLAG_GET_MASK = 0x1F,
  IO_FLAG_SET_MASK = 0x3
};

/** @ingroup glibmmEnums */
inline IOFlags operator|(IOFlags lhs, IOFlags rhs)
  { return static_cast<IOFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline IOFlags operator&(IOFlags lhs, IOFlags rhs)
  { return static_cast<IOFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline IOFlags operator^(IOFlags lhs, IOFlags rhs)
  { return static_cast<IOFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline IOFlags operator~(IOFlags flags)
  { return static_cast<IOFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup glibmmEnums */
inline IOFlags& operator|=(IOFlags& lhs, IOFlags rhs)
  { return (lhs = static_cast<IOFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline IOFlags& operator&=(IOFlags& lhs, IOFlags rhs)
  { return (lhs = static_cast<IOFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline IOFlags& operator^=(IOFlags& lhs, IOFlags rhs)
  { return (lhs = static_cast<IOFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/**  A bitwise combination representing an I/O condition to watch for on an
 * event source.
 * The flags correspond to those used by the <tt>%poll()</tt> system call
 * on UNIX (see <tt>man 2 poll</tt>).  To test for individual flags, do
 * something like this:
 * @code
 * if((condition & Glib::IO_OUT) != 0)
 *   do_some_output();
 * @endcode
 *  @var IOCondition IO_IN
 * There is data to read.
 * 
 *  @var IOCondition IO_OUT
 * Data can be written (without blocking).
 * 
 *  @var IOCondition IO_PRI
 * There is urgent data to read.
 * 
 *  @var IOCondition IO_ERR
 * Error condition.
 * 
 *  @var IOCondition IO_HUP
 * Hung up (the connection has been broken, usually for
 * pipes and sockets).
 * 
 *  @var IOCondition IO_NVAL
 * Invalid request. The file descriptor is not open.
 * 
 *  @enum IOCondition
 * 
 * A bitwise combination representing a condition to watch for on an
 * event source.
 *
 * @ingroup glibmmEnums
 * @par Bitwise operators:
 * <tt>%IOCondition operator|(IOCondition, IOCondition)</tt><br>
 * <tt>%IOCondition operator&(IOCondition, IOCondition)</tt><br>
 * <tt>%IOCondition operator^(IOCondition, IOCondition)</tt><br>
 * <tt>%IOCondition operator~(IOCondition)</tt><br>
 * <tt>%IOCondition& operator|=(IOCondition&, IOCondition)</tt><br>
 * <tt>%IOCondition& operator&=(IOCondition&, IOCondition)</tt><br>
 * <tt>%IOCondition& operator^=(IOCondition&, IOCondition)</tt><br>
 */
enum IOCondition
{
  IO_IN = G_IO_IN,
  IO_OUT = G_IO_OUT,
  IO_PRI = G_IO_PRI,
  IO_ERR = G_IO_ERR,
  IO_HUP = G_IO_HUP,
  IO_NVAL = G_IO_NVAL
};

/** @ingroup glibmmEnums */
inline IOCondition operator|(IOCondition lhs, IOCondition rhs)
  { return static_cast<IOCondition>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline IOCondition operator&(IOCondition lhs, IOCondition rhs)
  { return static_cast<IOCondition>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline IOCondition operator^(IOCondition lhs, IOCondition rhs)
  { return static_cast<IOCondition>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline IOCondition operator~(IOCondition flags)
  { return static_cast<IOCondition>(~static_cast<unsigned>(flags)); }

/** @ingroup glibmmEnums */
inline IOCondition& operator|=(IOCondition& lhs, IOCondition rhs)
  { return (lhs = static_cast<IOCondition>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline IOCondition& operator&=(IOCondition& lhs, IOCondition rhs)
  { return (lhs = static_cast<IOCondition>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline IOCondition& operator^=(IOCondition& lhs, IOCondition rhs)
  { return (lhs = static_cast<IOCondition>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/** Exception class for IOChannel errors.
 */
class IOChannelError : public Glib::Error
{
public:
  /**  @var Code FILE_TOO_BIG
   * File too large.
   * 
   *  @var Code INVALID_ARGUMENT
   * Invalid argument.
   * 
   *  @var Code IO_ERROR
   * IO error.
   * 
   *  @var Code IS_DIRECTORY
   * File is a directory.
   * 
   *  @var Code NO_SPACE_LEFT
   * No space left on device.
   * 
   *  @var Code NO_SUCH_DEVICE
   * No such device or address.
   * 
   *  @var Code OVERFLOWN
   * Value too large for defined datatype.
   * 
   *  @var Code BROKEN_PIPE
   * Broken pipe.
   * 
   *  @var Code FAILED
   * Some other error.
   * 
   *  @enum Code
   * 
   * %Error codes returned by IOChannel operations.
   */
  enum Code
  {
    FILE_TOO_BIG,
    INVALID_ARGUMENT,
    IO_ERROR,
    IS_DIRECTORY,
    NO_SPACE_LEFT,
    NO_SUCH_DEVICE,
    OVERFLOWN,
    BROKEN_PIPE,
    FAILED
  };

  IOChannelError(Code error_code, const Glib::ustring& error_message);
  explicit IOChannelError(GError* gobject);
  Code code() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  static void throw_func(GError* gobject);

  friend void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};


#ifndef DOXYGEN_SHOULD_SKIP_THIS
class GlibmmIOChannel;
#endif

/** IOChannel aims to provide portable I/O support for files, pipes
 * and sockets, and to integrate them with the GLib main event loop.
 *
 * Note that IOChannels implement an automatic implicit character set
 * conversion to the data stream, and usually will not pass by default
 * binary data unchanged.  To set the encoding of the channel, use e.g.
 * set_encoding("ISO-8859-15"). To set the channel to no encoding, use
 * set_encoding() without any arguments.
 *
 * You can create an IOChannel with one of the static create methods.
 */
class IOChannel : public sigc::trackable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef IOChannel CppObjectType;
  typedef GIOChannel BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


  IOChannel(IOChannel&& other) noexcept;
  IOChannel& operator=(IOChannel&& other) noexcept;

      
public:
  virtual ~IOChannel();

  /** Open a file @a filename as an I/O channel using mode @a mode.
   * This channel will be closed when the last reference to it is dropped,
   * so there is no need to call close() (though doing so will not cause
   * problems, as long as no attempt is made to access the channel after
   * it is closed).
   * @param filename The name of the file to open.
   * @param mode One of <tt>"r"</tt>, <tt>"w"</tt>, <tt>"a"</tt>,
   *  <tt>"r+"</tt>, <tt>"w+"</tt>, <tt>"a+"</tt>. These have the
   *  same meaning as in <tt>fopen()</tt>.
   * @return An IOChannel for the opened file.
   * @throw Glib::FileError
   */
  static Glib::RefPtr<IOChannel> create_from_file(const std::string& filename, const std::string& mode);
  

  /** Creates an I/O channel from a file descriptor.
   * On Unix, IOChannels created with this function work for any file
   * descriptor or socket.
   *
   * On Win32, this can be used either for files opened with the MSVCRT (the
   * Microsoft run-time C library) <tt>_open()</tt> or <tt>_pipe()</tt>,
   * including file descriptors 0, 1 and 2 (corresponding to <tt>stdin</tt>,
   * <tt>stdout</tt> and <tt>stderr</tt>), or for Winsock <tt>SOCKET</tt>s. If
   * the parameter is a legal file descriptor, it is assumed to be such,
   * otherwise it should be a <tt>SOCKET</tt>. This relies on <tt>SOCKET</tt>s
   * and file descriptors not overlapping. If you want to be certain, call
   * either create_from_win32_fd() or create_from_win32_socket() instead as
   * appropriate.
   *
   * The term file descriptor as used in the context of Win32 refers to the
   * emulated Unix-like file descriptors MSVCRT provides. The native
   * corresponding concept is file <tt>HANDLE</tt>. There isn't as of yet
   * a way to get IOChannels for Win32 file <tt>HANDLE</tt>s.
   */
  static Glib::RefPtr<IOChannel> create_from_fd(int fd);
  

#ifdef G_OS_WIN32

  /** Create an I/O channel for C runtime (emulated Unix-like) file descriptors.
   * After calling add_watch() on a I/O channel returned by this function, you
   * shouldn't call read() on the file descriptor. This is because adding
   * polling for a file descriptor is implemented on Win32 by starting a thread
   * that sits blocked in a <tt>%read()</tt> from the file descriptor most of
   * the time.  All reads from the file descriptor should be done by this
   * internal GLib thread. Your code should call only IOChannel::read().
   */
  static Glib::RefPtr<IOChannel> create_from_win32_fd(int fd);
  

  /** Create an I/O channel for a winsock socket. The parameter should be a
   * <tt>SOCKET</tt>. Contrary to I/O channels for file descriptors (on Win32),
   * you can use normal <tt>recv()</tt> or <tt>recvfrom()</tt> on sockets even
   * if GLib is polling them.
   */
  static Glib::RefPtr<IOChannel> create_from_win32_socket(int socket);
  

#endif /* G_OS_WIN32 */

  
  /** Read a single UCS-4 character.
   * @retval thechar The Unicode character.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  IOStatus read(gunichar& thechar);

  
  /** Read a character sequence into memory.
   * @param buf A buffer to read data into.
   * @param count The size of the buffer in bytes.  Note that the buffer may
   * not be complelely filled even if there is data in the buffer if the
   * remaining data is not a complete character.
   * @retval bytes_read The number of bytes read.  This may be zero even on
   * success if @a count < 6 and the channel's encoding is not <tt>""</tt>.
   * This indicates that the next UTF-8 character is too wide for the buffer.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  IOStatus read(char* buf, gsize count, gsize& bytes_read);

  /** Read a maximum of @a count bytes into @a str.
   * @param count The maximum number of bytes to read.
   * @retval str The characters that have been read.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  IOStatus read(Glib::ustring& str, gsize count);

  /** Read a whole line.
   * Reads until the line separator is found, which is included
   * in the result string.
   * @retval line The line that was read.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  IOStatus read_line(Glib::ustring& line);
  

  /** Reads all the remaining data from the file.
   * @retval str The resulting string.
   * @return Glib::IO_STATUS_NORMAL on success. This function never
   *  returns Glib::IO_STATUS_EOF.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  IOStatus read_to_end(Glib::ustring& str);
  

  /** Write a string to the I/O channel.
   * Note that this method does not return the number of characters written.
   * If the channel is blocking and the returned value is
   * Glib::IO_STATUS_NORMAL, the whole string was written.
   * @param str the string to write.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  IOStatus write(const Glib::ustring& str);

  
  /** Write a memory area of @a count bytes to the I/O channel.
   * @param buf The start of the memory area.
   * @param count The number of bytes to write.
   * @retval bytes_written The number of bytes written to the channel.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  IOStatus write(const char* buf, gssize count, gsize& bytes_written);

  
  /** Write a single UCS-4 character to the I/O channel.
   * @param unichar The character to write.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  IOStatus write(gunichar unichar);

  
  /** Seek the I/O channel to a specific position.
   * @param offset The offset in bytes from the position specified by @a type.
   * @param type A SeekType. The type Glib::SEEK_TYPE_CUR is only allowed in
   * those cases where a call to set_encoding() is allowed. See the
   * documentation for set_encoding() for details.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  IOStatus seek(gint64 offset, SeekType type =  SEEK_TYPE_SET);

  
  /** Flush the buffers of the I/O channel.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  IOStatus flush();

  
  /** Close the I/O channel.
   * Any pending data to be written will be flushed if @a flush is <tt>true</tt>.
   * The channel will not be freed until the last reference is dropped.
   * Accessing the channel after closing it is considered an error.
   * @param flush_pending Whether to flush() pending data before closing the channel.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   */
  IOStatus close(bool flush_pending =  true);

  
  /** Get the IOChannel internal buffer size.
   * @return The buffer size.
   */
  gsize get_buffer_size() const;

  
  /** Set the internal IOChannel buffer size.
   * @param size The buffer size the IOChannel should use.
   */
  void set_buffer_size(gsize size);

  
  /** Get the current flags for a IOChannel, including read-only
   * flags such as Glib::IO_FLAG_IS_READABLE.
   *
   * The values of the flags Glib::IO_FLAG_IS_READABLE and
   * Glib::IO_FLAG_IS_WRITEABLE are cached for internal use by the channel when
   * it is created.  If they should change at some later point (e.g. partial
   * shutdown of a socket with the UNIX <tt>shutdown()</tt> function), the user
   * should immediately call get_flags() to update the internal values of these
   * flags.
   * @return Bitwise combination of the flags set on the channel.
   */
  IOFlags get_flags() const;

  
  /** Set flags on the IOChannel.
   * @param flags Bitwise combination of the flags to set.
   * @return The operation result code.
   * @throw Glib::IOChannelError
   */
  IOStatus set_flags(IOFlags flags);

  
  /** Set the buffering status of the I/O channel.
   * The buffering state can only be set if the channel's encoding is
   * <tt>""</tt>. For any other encoding, the channel must be buffered.
   *
   * A buffered channel can only be set unbuffered if the channel's internal
   * buffers have been flushed. Newly created channels or channels which have
   * returned Glib::IO_STATUS_EOF not require such a flush. For write-only
   * channels, a call to flush() is sufficient. For all other channels, the
   * buffers may be flushed by a call to seek().  This includes the possibility
   * of seeking with seek type Glib::SEEK_TYPE_CUR and an offset of zero. Note
   * that this means that socket-based channels cannot be set unbuffered once
   * they have had data read from them.
   *
   * The default state of the channel is buffered.
   *
   * @param buffered Whether to set the channel buffered or unbuffered.
   */
  void set_buffered(bool buffered);

  
  /** Get the buffering status of the I/O channel.
   * @return The buffering status of the channel.
   */
  bool get_buffered() const;

  
  /** Returns an IOCondition depending on whether there is data to be
   * read/space to write data in the internal buffers in the I/O channel.
   * Only the flags Glib::IO_IN and Glib::IO_OUT may be set.
   * @return Bitwise combination of Glib::IOCondition flags.
   */
  IOCondition get_buffer_condition() const;

  
  /** Returns whether the file/socket/whatever associated with the I/O channel
   * will be closed when the channel receives its final unref and is destroyed.
   * The default value of this is <tt>true</tt> for channels created by
   * create_from_file(), and <tt>false</tt> for all other channels.
   * @return Whether the channel will be closed on the final unref of the
   * IOChannel object.
   */
  bool get_close_on_unref() const;

  
  /** Setting this flag to <tt>true</tt> for a channel you have already closed
   * can cause problems.
   * @param do_close Whether to close the channel on the final unref of the
   * IOChannel object.  The default value of this is <tt>true</tt> for channels
   * created by create_from_file(), and <tt>false</tt> for all other channels.
   */
  void set_close_on_unref(bool do_close);

  /** Sets the encoding for the input/output of the channel.
   * The internal encoding is always UTF-8.  The default encoding for the
   * external file is UTF-8.  The encoding <tt>""</tt> is safe to use with
   * binary data.
   *
   * The encoding can only be set if one of the following conditions
   * is true:
   *
   * -# The channel was just created, and has not been written to or read from
   *  yet.
   * -# The channel is write-only.
   * -# The channel is a file, and the file pointer was just repositioned by a
   *  call to seek_position().  (This flushes all the internal buffers.)
   * -# The current encoding is <tt>""</tt> or UTF-8.
   * -# One of the read methods has just returned Glib::IO_STATUS_EOF (or, in
   *  the case of read_to_end(), Glib::IO_STATUS_NORMAL).
   * -# The read() method has returned Glib::IO_STATUS_AGAIN or thrown
   *  a Glib::Error exception.  This may be useful in the case of
   *  ConvertError::ILLEGAL_SEQUENCE.  Returning one of these statuses
   *  from read_line() or read_to_end() does <em>not</em> guarantee that
   *  the encoding can be changed.
   *
   * Channels which do not meet one of the above conditions cannot call
   * seek_position() with a seek type of Glib::SEEK_TYPE_CUR and, if they
   * are "seekable", cannot call write() after calling one of the API
   * "read" methods.
   *
   * @param encoding The encoding name, or <tt>""</tt> for binary.
   * @return Glib::IO_STATUS_NORMAL if the encoding was successfully set.
   * @throw Glib::IOChannelError
   */
  IOStatus set_encoding(const std::string& encoding = std::string());
  

  /** Get the encoding of the I/O channel.
   * @return The current encoding of the channel.
   */
  std::string get_encoding() const;
  

  void set_line_term(const std::string& term = std::string());
  

  std::string get_line_term() const;
  

  /** Creates an IOSource object.
   * Create a slot from a function to be called when condition is met
   * for the channel with sigc::ptr_fun() or sigc::mem_fun() and pass
   * it into the connect() function of the returned IOSource object.
   * Polling of the channel will start when you attach a MainContext
   * object to the returned IOSource object using its attach() function.
   *
   * Glib::signal_io().connect() is a simpler interface to the same
   * functionality, for the case where you want to add the source to the
   * default main context.
   * @param condition The condition to watch for.
   * @return An IOSource object that can be polled from a MainContext's event loop.
   */
  Glib::RefPtr<IOSource> create_watch(IOCondition condition);

  virtual void reference()   const;
  virtual void unreference() const;
  

  GIOChannel*       gobj()       { return gobject_; }
  const GIOChannel* gobj() const { return gobject_; }

protected:
  GIOChannel* gobject_;

  /** Constructor that should be used by derived classes.
   * Use this constructor if you want to inherit from IOChannel.
   * It will set up a GIOChannel that will call the vfuncs of your
   * class even if it is being used from C code, and it will keep
   * a reference to the C++ code while the GIOChannel exists.
   */
  IOChannel();
  

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  IOChannel(GIOChannel* gobject, bool take_copy);
#endif

  //We don't put GLIBMM_DISABLE_DEPRECATED around these deprecated methods
  //because they are virtual and that would make the ABI dependent on the ifdef.

  /**
   * @deprecated Custom Glib::IOChannel implementation was never really supported.
   */
  virtual IOStatus read_vfunc(char* buf, gsize count, gsize& bytes_read);

  /**
   * @deprecated Custom Glib::IOChannel implementation was never really supported.
   */
  virtual IOStatus write_vfunc(const char* buf, gsize count, gsize& bytes_written);

  /**
   * @deprecated Custom Glib::IOChannel implementation was never really supported.
   */
  virtual IOStatus seek_vfunc(gint64 offset, SeekType type);

  /**
   * @deprecated Custom Glib::IOChannel implementation was never really supported.
   */
  virtual IOStatus close_vfunc();

  /**
   * @deprecated Custom Glib::IOChannel implementation was never really supported.
   */
  virtual IOStatus set_flags_vfunc(IOFlags flags);

  /**
   * @deprecated Custom Glib::IOChannel implementation was never really supported.
   */
  virtual IOFlags  get_flags_vfunc();

  /**
   * @deprecated Custom Glib::IOChannel implementation was never really supported.
   */
  virtual Glib::RefPtr<Glib::Source> create_watch_vfunc(IOCondition cond);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  friend class Glib::GlibmmIOChannel;
#endif

private:
  void release_gobject();


};

Glib::RefPtr<IOChannel> wrap(GIOChannel* gobject, bool take_copy = false);

} // namespace Glib


#endif /* _GLIBMM_IOCHANNEL_H */

