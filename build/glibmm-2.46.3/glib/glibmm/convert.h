// -*- c++ -*-
// Generated by gmmproc 2.46.3 -- DO NOT MODIFY!
#ifndef _GLIBMM_CONVERT_H
#define _GLIBMM_CONVERT_H


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
#include <glibmm/error.h>
#include <glibmm/ustring.h>
#include <glib.h> /* for gsize */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GIConv* GIConv; }
#endif


namespace Glib
{

/** @defgroup CharsetConv Character Set Conversion
 * Utility functions for converting strings between different character sets.
 * @{
 */

/** Exception class for charset conversion errors.
 * Glib::convert() and friends throw a ConvertError exception if the charset
 * conversion failed for some reason.  When writing non-trivial applications
 * you should always catch those errors, and then try to recover, or tell the
 * user the input was invalid.
 */
class ConvertError : public Glib::Error
{
public:
  /**  @var Code NO_CONVERSION
   * Conversion between the requested character
   * sets is not supported.
   * 
   *  @var Code ILLEGAL_SEQUENCE
   * Invalid byte sequence in conversion input.
   * 
   *  @var Code FAILED
   * Conversion failed for some reason.
   * 
   *  @var Code PARTIAL_INPUT
   * Partial character sequence at end of input.
   * 
   *  @var Code BAD_URI
   * URI is invalid.
   * 
   *  @var Code NOT_ABSOLUTE_PATH
   * Pathname is not an absolute path.
   * 
   *  @var Code NO_MEMORY
   * No memory available. @newin{2,40}
   * 
   *  @enum Code
   * 
   * %Error codes returned by character set conversion routines.
   */
  enum Code
  {
    NO_CONVERSION,
    ILLEGAL_SEQUENCE,
    FAILED,
    PARTIAL_INPUT,
    BAD_URI,
    NOT_ABSOLUTE_PATH,
    NO_MEMORY
  };

  ConvertError(Code error_code, const Glib::ustring& error_message);
  explicit ConvertError(GError* gobject);
  Code code() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  static void throw_func(GError* gobject);

  friend void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};


/** Thin %iconv() wrapper.
 * glibmm provides Glib::convert() and Glib::locale_to_utf8() which
 * are likely more convenient than the raw iconv wrappers.  However,
 * creating an IConv object once and using the convert() method could
 * be useful when converting multiple times between the same charsets.
 */
class IConv
{
public:
  /** Open new conversion descriptor.
   * @param to_codeset Destination codeset.
   * @param from_codeset %Source codeset.
   * @throw Glib::ConvertError
   */
  IConv(const std::string& to_codeset, const std::string& from_codeset);
  

  IConv(const IConv&) = delete;
  IConv& operator=(const IConv&) = delete;

  explicit IConv(GIConv gobject);

  /** Close conversion descriptor.
   */
  ~IConv();
  

  /** Same as the standard UNIX routine %iconv(), but may be implemented
   * via libiconv on UNIX flavors that lack a native implementation.  glibmm
   * provides Glib::convert() and Glib::locale_to_utf8() which are likely
   * more convenient than the raw iconv wrappers.
   * @param inbuf Bytes to convert.
   * @param inbytes_left In/out parameter, bytes remaining to convert in @a inbuf.
   * @param outbuf Converted output bytes.
   * @param outbytes_left In/out parameter, bytes available to fill in @a outbuf.
   * @return Count of non-reversible conversions, or <tt>static_cast<std::size_t>(-1)</tt> on error.
   */
  std::size_t iconv(char** inbuf, gsize* inbytes_left, char** outbuf, gsize* outbytes_left);
  

  /** Reset conversion descriptor to initial state.
   * Same as <tt>iconv(0, 0, 0, 0)</tt>, but implemented slightly differently
   * in order to work on Sun Solaris <= 7.  It's also more obvious so you're
   * encouraged to use it.
   */
  void reset();

  /** Convert from one encoding to another.
   * @param str The string to convert.
   * @return The converted string.
   * @throw Glib::ConvertError
   */
  std::string convert(const std::string& str);

  GIConv gobj() { return gobject_; }

private:
  GIConv gobject_;
};


/** Get the charset used by the current locale.
 * @return Whether the current locale uses the UTF-8 charset.
 */
bool get_charset();

/** Get the charset used by the current locale.
 * @param charset Will be filled with the charset's name.
 * @return Whether the current locale uses the UTF-8 charset.
 */
bool get_charset(std::string& charset);

/** Convert from one encoding to another.
 * @param str The string to convert.
 * @param to_codeset Name of the target charset.
 * @param from_codeset Name of the source charset.
 * @return The converted string.
 * @throw Glib::ConvertError
 */
std::string convert(const std::string& str,
                    const std::string& to_codeset,
                    const std::string& from_codeset);

/** Converts a string from one character set to another, possibly including
 * fallback sequences for characters not representable in the output.
 * Characters not in the target encoding will be represented as Unicode
 * escapes <tt>\\x{XXXX}</tt> or <tt>\\x{XXXXXX}</tt>.
 * @param str The string to convert.
 * @param to_codeset Name of the target charset.
 * @param from_codeset Name of the source charset.
 * @return The converted string.
 * @throw Glib::ConvertError
 */
std::string convert_with_fallback(const std::string& str,
                                  const std::string& to_codeset,
                                  const std::string& from_codeset);

/** Converts a string from one character set to another, possibly including
 * fallback sequences for characters not representable in the output.
 * @note It is not guaranteed that the specification for the fallback sequences
 * in @a fallback will be honored. Some systems may do a approximate conversion
 * from @a from_codeset to @a to_codeset in their iconv() functions, in which
 * case Glib will simply return that approximate conversion.
 *
 * @param str The string to convert.
 * @param to_codeset Name of the target charset.
 * @param from_codeset Name of the source charset.
 * @param fallback UTF-8 string to be used in place of characters which aren't
 *  available in the target encoding.  All characters in the fallback string
 *  @em must be available in the target encoding.
 * @return The converted string.
 * @throw Glib::ConvertError
 */
std::string convert_with_fallback(const std::string& str,
                                  const std::string& to_codeset,
                                  const std::string& from_codeset,
                                  const Glib::ustring& fallback);

/** Convert from the current locale's encoding to UTF-8.
 * Convenience wrapper around Glib::convert().
 * @param opsys_string The string to convert.  Must be encoded in the charset
 *  used by the operating system's current locale.
 * @return The input string converted to UTF-8 encoding.
 * @throw Glib::ConvertError
 */
Glib::ustring locale_to_utf8(const std::string& opsys_string);

/** Convert from UTF-8 to the current locale's encoding.
 * Convenience wrapper around Glib::convert().
 * @param utf8_string The UTF-8 string to convert.
 * @return The input string converted to the charset used by the operating
 *  system's current locale.
 * @throw Glib::ConvertError
 */
std::string locale_from_utf8(const Glib::ustring& utf8_string);

/** Converts a string which is in the encoding used for filenames into
 * a UTF-8 string.
 * @param opsys_string A string in the encoding for filenames.
 * @return The converted string.
 * @throw Glib::ConvertError
 */
Glib::ustring filename_to_utf8(const std::string& opsys_string);

/** Converts a string from UTF-8 to the encoding used for filenames.
 * @param utf8_string A UTF-8 encoded string.
 * @return The converted string.
 * @throw Glib::ConvertError
 */
std::string filename_from_utf8(const Glib::ustring& utf8_string);

/** Converts an escaped UTF-8 encoded URI to a local filename
 * in the encoding used for filenames.
 * @param uri A string in the encoding for filenames.
 * @param hostname Location to store hostname for the URI. If there is no
 *   hostname in the URI, <tt>""</tt> will be stored in this location.
 * @return The resulting filename.
 * @throw Glib::ConvertError
 */
std::string filename_from_uri(const Glib::ustring& uri, Glib::ustring& hostname);

/** Converts an escaped UTF-8 encoded URI to a local filename in the encoding
 * used for filenames.
 * @param uri A string in the encoding for filenames.
 * @return The resulting filename.
 * @throw Glib::ConvertError
 */
std::string filename_from_uri(const Glib::ustring& uri);

/** Converts an absolute filename to an escaped UTF-8 encoded URI.
 * @param filename An absolute filename specified in the encoding used
 *   for filenames by the operating system.
 * @param hostname A UTF-8 encoded hostname.
 * @return The resulting URI.
 * @throw Glib::ConvertError
 */
Glib::ustring filename_to_uri(const std::string& filename, const Glib::ustring& hostname);

/** Converts an absolute filename to an escaped UTF-8 encoded URI.
 * @param filename An absolute filename specified in the encoding used
 *   for filenames by the operating system.
 * @return The resulting URI.
 * @throw Glib::ConvertError
 */
Glib::ustring filename_to_uri(const std::string& filename);

/** Returns the display basename for the particular filename, guaranteed
 * to be valid UTF-8. The display name might not be identical to the filename,
 * for instance there might be problems converting it to UTF-8, and some files
 * can be translated in the display
 *
 * You must pass the whole absolute pathname to this function so that
 * translation of well known locations can be done.
 *
 * This function is preferred over filename_display_name() if you know the
 * whole path, as it allows translation.
 *
 * @param filename An absolute pathname in the GLib file name encoding.
 * @result A string containing a rendition of the basename of the filename in valid UTF-8
 */
Glib::ustring filename_display_basename(const std::string& filename);

/** Converts a filename into a valid UTF-8 string. The
 * conversion is not necessarily reversible, so you
 * should keep the original around and use the return
 * value of this function only for display purposes.
 * Unlike g_filename_to_utf8(), the result is guaranteed
 * to be non-empty even if the filename actually isn't in the GLib
 * file name encoding.
 *
 * If you know the whole pathname of the file you should use
 * g_filename_display_basename(), since that allows location-based
 * translation of filenames.
 *
 * @param filename: a pathname hopefully in the GLib file name encoding
 * @result A string containing a rendition of the filename in valid UTF-8.
 */
Glib::ustring filename_display_name(const std::string& filename);

/** @} group CharsetConv */

} // namespace Glib


#endif /* _GLIBMM_CONVERT_H */

