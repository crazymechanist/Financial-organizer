#include <iostream>
#include "Markup.h"
#include "Date.h"
#include "User.h"
#include "UserManager.h"


using namespace std;

int main()
{
UserManager userManager;

userManager.registerUser();

userManager.logInUser();

userManager.changePasswordOfLogInUser();

userManager.logOutUser();

userManager.logInUser();





    return 0;
}
