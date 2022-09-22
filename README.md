# MM-Task

Hi, I'll try to provide more details about the project here. I have tried to add comments in the code as much as possible. I hope you like it, and any feedback is appreciated! 

Cheers, 
Burak.

## 📜General info
- All C++ files have **MM** prefix.
- C++ Interfaces have **Interface** suffix.
- C++ classes are not directly used in the project. BP children are created and used.
- Blueprints, Maps and Widgets are under `/Content/Task/` folder.
- I used C++ for the core logic, but used Blueprints for the interaction/communication, and also in the widgets.
- Some functions are exposed to Blueprints and called from there as well.
- I used interfaces to make communication between classes more extendeable and flexible.
- You can play it on standalone net mode.


# 📂 Files / Classes


## C++ Files
|Class name                  | Details                                               |
|----------------------------|-------------------------------------------------------|
| MMGameMode.h                | Default game mode for third person template. No changes.
| MMBaseCharacter.h           | Default character in the third person template. No changes.  
| MMCharacter.h               | Inherits from `MMBaseCharacter.h` <br> Implements `MMCharacterDetailsInterface.h` <br> Contains extra logic for Overhead text for displaying playerer name.  
| MMDoor.h                    | Implements `MMInteractionInterface.h` <br> Contains logic for opening/closing the door (Replicated)
| MMLever.h                   | Implements `MMInteractionInterface.h` <br> Contains logic for activating/deactivating lever. <br> Contains a `TargetActor` variable to interact with another actor.
| MMGameInstance.h            | Implements `MMPlayerDetailsInterface.h` <br> Contains only **PlayerName** variable to store it persistently between levels
| MMPlayerDetailsInterface.h  | Contains **SetPlayerName** and **GetPlayerName** functions. 
| MMInteractionInterface.h    | Contains **Interact** function.
| MMLobbyInterface.h          | Contains **HostGame** and **JoinGame** functions.

## Blueprints
|Class name               | Details                                                    |
|-------------------------|------------------------------------------------------------|
| BP_Character            | Inherits from `MMCharacter.h` <br> No extra logic.
| BP_Lever                | Inherits from `MMLever.h` <br> Handles interaction.
| BP_Door                 | Inherits from `MMDoor.h` <br> Handles interaction and animating door.
| BP_PlayerController     | Handles input, setting player name and interaction with the lever. <br>
| BP_GameInstance         | Inherits from `MMGameInstance.h` <br> No extra logic.
| BP_GameMode             | Inherits from `MMGameMode.h` <br> No extra logic.
| BP_LobbyGameMode        | Contains logic for creating/joining a session.

## Widgets
|Class name          | Details                                                    |
|--------------------|------------------------------------------------------------|
|WBP_Lobby           | Handles user input for creating/joining a session.
|WBP_Info            | Shows interaction button after starting the game.

## Maps
|Class name          | Details                                                    |
|--------------------|------------------------------------------------------------|
| LobbyMap           | Blank level for lobby
| DoorAndLeverLevel  | Modified third person example map


