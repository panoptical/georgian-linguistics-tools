/* 
 * File:   kartio.h
 * Author: Neal Zupancic
 *
 * This is primarily a set of functions to deal with reading, writing, and
 * storing Georgian characters.  These functions read Georgian characters
 * encoded in UTF-8, store them internally in single-byte characters, and 
 * can write them back to a file in UTF-8.  The internal storage uses decimal
 * values 144-176, which were chosen for speed and efficiency and which will
 * not clash with any standard ASCII characters.  
 * 
 * AT this time the system can handle files with UTF-8 encoding and is designed
 * specifically for Georgian characters.  Files that are not encoded with UTF-8
 * can cause unexpected behavior.  Files that contain other three-byte UTF-8
 * characters may also suffer unintended results but will probably be okay.  The
 * system is designed so that if it sees something that is not a Georgian 
 * character it will try to leave it alone.
 *
 * Internal storage of Georgian characters as single-byte data of type "char"
 * allows use of the full functionality built around chars in C++, including
 * strings and standard i/o.  It is also fast and memory-efficient.
 * 
 * "dekart" (pronounced "Descartes") takes a string and returns the same string,
 * but with the UTF-8 encoded Georgian characters replaced by single-byte 
 * Georgian characters.  dekart can be used on input read in from a file,
 * or on literals the programmer types.  So, if you want to build a stemmer to
 * deal with Georgian nouns, you will need a way to program with readable 
 * Georgian characters.  Simply use, for example, dekart("ის") to generate a
 * string that stores the Georgian characters ის in the internal format.
 * 
 * It's called "dekart" because it takes kartuli characters and makes them be
 * not kartuli anymore.
 * 
 * "rekart" takes a string and returns the same string, but with internal format
 * Georgian characters replaced with their UTF-8 encoded characters.  Use this
 * for writing to a file.
 * 
 * "iska" determines if a character is a Georgian letter.  It is similar in 
 * function and purpose to "isalpha", the c standard function that determines
 * if a character is a Latin letter.
 * 
 * "keytrans" and "detrans" are used for switching between Georgian characters 
 * and their transliterated equivalents, based on the keyboard transcription 
 * used by Georgians when typing.  So a=ა, W = ჭ, etc.  keytrans goes from 
 * Georgian to Latin, and detrans goes from Latin to Georgian (internal).  In 
 * other words, keytrans produces the keyboard transcription of Georgian
 * characters, while detrans detranscribes the characters.  
 * 
 * Use "rekart(detrans("string here"))" to return a UTF-8 encoded version of a
 * string typed in Georgian keyboard transcription.
 * 
 * 
 * Example of use:
 * 
 *  - read from a UTF-8 file into a string
 *  - dekart the string
 *  - perform normal string operations as you would with Latin words
 *   - alphabetization using normal comparison operators
 *   - iska tells you if a character is Georgian
 *   - edit, delete, replace using string accessors
 *   - remember to use dekart on literals before comparing/adding them
 *   - use keytrans with cout for readability!
 *   - use detrans with cin if you want to enter Georgian text from the console
 *   - etc.
 *  - rekart the string before writing it to a file
 *  - output will be in UTF-8
 * 
 * 
 * 
 * 
 * 
 * Created on November 24, 2012, 4:37 PM
 */


#ifndef KARTIO_H
#define	KARTIO_H


#define FIR 225; //defines the first character of a UTF-8 Georgian character
#define SEC 131; //defines the second character of a UTF-8 Georgian character

#include <cstdlib>
#include <string>

using namespace std;


/*function: bool iska(char c)
 *returns true if c is (an internal representation of) a Georgian character 
 * analogous to "bool isalpha(char c)" - c function that returns true if c 
 * is a latin character.
 */
bool iska(char c);

/*function: string dekart(string s)
 * takes a string that might contain UTF-8 encoded Georgian characters
 * returns the same string, but with any Georgian characters it finds
 * represented by a single byte
 * Works by removing the first two UTF-8 bytes 
 */
string dekart (string s); 


/*function: string rekart(string s)
 * takes a regular string
 * returns the same string, but any Georgian characters have been re-encoded
 * as UTF-8 Georgian characters
 */
string rekart (string s); 

/*function keytrans (string s)
 * takes a string
 * if the string contains any Georgian characters, transliterate them into Latin
 * using the standard keyboard transcription code 
 * 
 **/
string keytrans (string s); 

/*function detrans (string s)
 * takes a string
 * replaces any Latin characters in that string with their Georgian equivalents,
 * if they have any, using the standard keyboard transcription code 
 */
string detrans(string s);

/*function kar (string s)
 * takes a string
 * returns the first character in the string
 * if the first character is a UTF-8 Georgian character, it returns the single-byte
 * representation of that character supplied by dekart
 */
char kar (string s);


#endif	/* KARTIO_H */

