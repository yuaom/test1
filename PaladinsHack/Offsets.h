//BLUEFIRE1337 PALADINS SDK - UPDATED 2021-07-22
#pragma once

constexpr auto ENGINE = 0x371D890; //process_base + ENGINE -> UEngine 

constexpr auto LOCALPLAYER = 0x6D8;//0x6D4; //UEngine -> localPlayer
constexpr auto CONTROLLER = 0x68; //localPlayer -> controller

constexpr auto ROTATION = 0x008C; // controller -> rotation | FRotator
constexpr auto WORLD_INFO = 0x0120; // controller -> worldInfo

constexpr auto ACKNOWLEDGEDPAWN = 0x0498; //controller -> acknowledgedPawn
constexpr auto REPLICATIONINFO = 0x0290; //controller -> replicationInfo
constexpr auto PLAYER_FOV_MULTIPLIER = 0x04CC; //controller -> FOVMultiplier, aka LODDistanceFactor | float
constexpr auto CAMERA = 0x0478; //controller -> camera

constexpr auto REAL_LOCATION = 0x0494; // camera -> reallocation | FVector
constexpr auto DEAFULT_FOV = 0x0290; //camera -> fov | float
//FOV = DEAFULT_FOV * PLAYER_FOV_MULTIPLIER

constexpr auto PAWN_LIST = 0x05B4; // worldInfo -> pawnList
constexpr auto TIMESECONDS = 0x04EC; // worldInfo -> TimeSeconds | float

constexpr auto TEAM = 0x4DC; // PlayerReplicationInfo -> Team 
constexpr auto TEAMINDEX = 0x298; // Team -> TeamIndex | int

constexpr auto AMMO_COUNT = 0x4A4; // weapon -> ammo | int
constexpr auto AMMO_MAX_COUNT = 0x5F0;// 0x4A8; // weapon -> ammo | int

constexpr auto GLOW = 0x674;// awpawn -> glow
constexpr auto THIRDPERSON = 0x0624;// awpawn -> write float
constexpr auto WEAPON = 0x04E4; // pawn -> weapon
constexpr auto BASE_EYE_HEIGHT = 0x03A4; // pawn -> BaseEyeHeight | float
constexpr auto HEALTH = 0x3C4; // pawn -> hp | int
constexpr auto LOCATION = 0x0080; // pawn -> location | FVector
constexpr auto VELOCITY = 0x0190; // pawn -> velocity | FVector
constexpr auto PLAYER_REPLICATION_INFO = 0x0440; // pawn -> PlayerReplicationInfo
constexpr auto NEXT_PAWN = 0x02AC; // pawn -> nextpawn
constexpr auto MESH = 0x048C; // pawn -> mesh

constexpr auto BOUNDS = 0x00A0; // mesh -> bounds | FBoxSphereBounds
constexpr auto LAST_RENDER_TIME = 0x0244; // mesh -> LastRenderTime | float