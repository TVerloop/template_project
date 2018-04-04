//  ___________                   .__          __
//  \__    ___/___   _____ ______ |  | _____ _/  |_  ____
//    |    |_/ __ \ /     \\____ \|  | \__  \\   __\/ __ \
//    |    |\  ___/|  Y Y  \  |_> >  |__/ __ \|  | \  ___/
//    |____| \___  >__|_|  /   __/|____(____  /__|  \___  >
//               \/      \/|__|             \/          \/
//
/// @file example.cpp
/// @author T. Verloop <t93.verloop@gmail.com>
/// @version 0.1
/// @date 04-04-2018
/// @todo Issue 006: Make this example more examplier.
/// @bug Issue 005: Bug happening in this file.
/// @warning Watch out for something.
/// @copyright Some random software license.
/// @brief template example.cpp file.
///
/// @detail An example source file problably best to delete and start your own.
///

//****************************************************************************//
// Includes.
//****************************************************************************//

// System.

// Third Party.

// Local.
#include <example.hpp>

namespace examples {

bool example::function(int arg_in, char & arg_out) {
    arg_out = static_cast<char>(arg_in);
    return true;
}

/// example private function.
///
/// @param[in]  arg_in      Number of arguments given at start.
/// @param[out] arg_out     Array of C string arguments.
///
/// @return
///         @li true    function exited successfully.
///         @li false   function exited unsuccessfully.
bool example::function_(int arg_in, char & arg_out) {
    arg_out = static_cast<char>(arg_in);
    return true;
}

}
