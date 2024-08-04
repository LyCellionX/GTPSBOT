# GTPSBOT

## Description
This code was originally created by Sundei and remade by Me and Time.

## How To Use
1. **Update Project Properties:**
   - Go to your GTPS Solution property pages.
   - Navigate to "Input" > "Linker" and paste the following:
     ```
     winmm.lib;fmt.lib;dpp.lib;%(AdditionalDependencies)
     ```
   - Then, apply the changes.

2. **Include Files:**
   - Extract the `include.rar` file.
   - Paste the extracted files into your GTPS include directory.
   - Change the `World.h` include as shown in the picture below:
     ![image](https://github.com/user-attachments/assets/aff7b50c-1afb-4255-bedb-46d748bf226c)

## Code to Copy
Copy and paste the following code into your project:

```cpp
#pragma warning(push)
#pragma warning(disable: 26812)
#pragma warning(disable: 6054)
#pragma warning(disable: 6385)
#pragma warning(disable: 4267)
#pragma warning(disable: 4244)
#pragma warning(disable: 4267)

#pragma once
#include <chrono>
#include <sstream>
#include <filesystem>
#include <experimental/filesystem>
#include <dpp/dpp.h>
#include <leo_referance.hpp>
#include "Time.h"
#include "wincrypt.h"
#include "ncrypt.h"
#include <functional>
```

# Config
Configuration
Update Discord.h:
Replace the placeholders with your actual bot token, Discord server ID, and command channel ID.

```cpp
dpp::cluster bot("INPUT YOUR BOT TOKEN HERE", dpp::i_default_intents | dpp::i_message_content);
dpp::snowflake guild_ = 819127381283123; // Input your Discord Server ID
dpp::snowflake channel_id = 12528123330999; // Input your bot command channel ID here
vector<thread> tasks;
```

# How to Start
Update Source.cpp:

Press Ctrl + Shift + F and search for int main.
Copy and paste the following code inside the main function:
cpp
Copy code
```cpp
tasks.emplace_back(bot_gateway);
tasks.emplace_back(UpdateStatus);
```
Build Project:
Once the above steps are completed, build your GTPS solution project.
