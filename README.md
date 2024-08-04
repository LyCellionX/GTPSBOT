# GTPSBOT
# This Code was created by Sundei Remaked By Me And Time
# How To Use:
- Go to your GTPS Solution property pages
- Go to "Input" > "Linker" then paste this-
      # winmm.lib;fmt.lib;dpp.lib;%(AdditionalDependencies)
- Then Apply
- If done extract the include.rar and paste to your GTPS include sln
- Change The World.h include like this pic
![image](https://github.com/user-attachments/assets/aff7b50c-1afb-4255-bedb-46d748bf226c)

# Copy This
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
- Go to Discord.h
```cpp
dpp::cluster bot("INPUT YOUR BOT TOKEN HERE", dpp::i_default_intents | dpp::i_message_content);
dpp::snowflake guild_ = 819127381283123; //Input your discord Server ID
dpp::snowflake channel_id = 12528123330999; //input your bot command channel id here
vector<thread> tasks;```
- Change This to yours Bot token,Discord Server,Channel id

# How to Start?:
- Go to Source.cpp and Ctrl + shift + f and find int main
- then copy and paste thiscode 
```cpp
tasks.emplace_back(bot_gateway);
tasks.emplace_back(UpdateStatus);```
- If done Build your gtps solution project
