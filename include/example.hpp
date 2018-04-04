//  ___________                   .__          __
//  \__    ___/___   _____ ______ |  | _____ _/  |_  ____
//    |    |_/ __ \ /     \\____ \|  | \__  \\   __\/ __ \
//    |    |\  ___/|  Y Y  \  |_> >  |__/ __ \|  | \  ___/
//    |____| \___  >__|_|  /   __/|____(____  /__|  \___  >
//               \/      \/|__|             \/          \/
//
/// @file example.hpp
/// @author T. Verloop <t93.verloop@gmail.com>
/// @version 0.1
/// @date 04-04-2018
/// @todo Issue 004: Make this example more examplier.
/// @bug Issue 003: Bug happening in this file.
/// @warning Watch out for something
/// @copyright Some random software license.
/// @brief Example header file.
///
/// @detail An example class problably best to delete and start your own.
///

//****************************************************************************//
// Includes.
//****************************************************************************//

// System.
#include <cstddef>

// Third Party.

// Local.

#ifndef EXAMPLES_EXAMPLE_HPP__
#define EXAMPLES_EXAMPLE_HPP__

/// @addtogroup examples
/// group documentation
/// @{

namespace examples {

//****************************************************************************//
// Defines.
//****************************************************************************//

/// @brief A simple macro example
#define SIMPLE_MACRO 1

/// @brief A simple macro function
/// @param[in] x    Input X.
/// @param[in] y    Input Y.
/// @return
///         @li     The highest of the two inputs
#define MACRO_FUNCION(x, y) (((x) > (y)) ? (x) : (y))

//****************************************************************************//
// Typedefs.
//****************************************************************************//

/// @brief An example enumerator
///
/// An example of an enumerator.
///
enum class enumerator_e {
    STATUS_1,               ///< Status one.
    STATUS_2,               ///< Status two.
    STATUS_3                ///< Status three.
};

///
/// @brief An example class.
///
/// An example class to give an idea of how to define these whith proper
/// documentation
///
/// @ingroup examples
///
class example {
public:
    /// Main function. The entry point of most applications.
    ///
    /// @param[in]  arg_in      Number of arguments given at start.
    /// @param[out] arg_out     Array of C string arguments.
    ///
    /// @return
    ///         @li true    function exited successfully.
    ///         @li false   function exited unsuccessfully.
    bool function(int arg_in, char & arg_out);
private:
    bool function_(int arg_in, char & arg_out);
};

}


/// @}

#endif // EXAMPLES_EXAMPLE_HPP__
