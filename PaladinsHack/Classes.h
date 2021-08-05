// MADE BY BLUEFIRE1337

#pragma once
#include <cstdint>
#include "Offsets.h"
#include "GameClasses.h"
#include "Mhyprot/baseadress.h"

template<class T>
class TArray
{
	//friend struct FString;
public:
	int Length() const
	{
		return m_nCount;
	}

	bool IsValid() const
	{
		if(m_nCount > m_nMax)
			return false;
		if(!m_Data)
			return false;
		return true;
	}

	uint64_t GetAddress() const
	{
		return m_Data;
	}

	T GetById(int i)
	{
		return read<T>(m_Data + i * 8);
	}


protected:
	uint64_t m_Data;
	uint32_t m_nCount;
	uint32_t m_nMax;
};

class USkeletalMeshComponent {
public:
	inline FBoxSphereBounds GetBounds() {
		return read<FBoxSphereBounds>(data + BOUNDS);
	}

	inline float GetLastRenderTime() {
		return read<float>(data + LAST_RENDER_TIME);
	}

	inline bool IsVisible(float timeSeconds) {
		float lastRenderTime = GetLastRenderTime();
		return (lastRenderTime > timeSeconds - 0.05f);
	}

	uint64_t data;
};

class ATeamInfo {
public:
	inline int GetTeamIndex() {
		return read<int>(data + TEAMINDEX);
	}

	uint64_t data;
};

class APlayerReplicationInfo {
public:
	ATeamInfo GetTeamInfo() {
		return read<ATeamInfo>(data + TEAM);
	}

	uint64_t data;
};

class ATgDevice {
public:
	inline int GetAmmoCount() {
		return read<int>(data + AMMO_COUNT);
	}

	inline int GetMaxAmmoCount() {
		return read<int>(data + AMMO_MAX_COUNT);
	}

	inline void SetPerspective(bool thirdPerson) {
		write<float>(data + THIRDPERSON, thirdPerson ? 1.f : 0.f); // THIS SETS THE DURATION OF THE PERSPECIVE IN SEC
	}

	uint64_t data;
};

class APawn {
public:
	inline ATgDevice GetWeapon() {
		return read<ATgDevice>(data + WEAPON);
	}

	inline int GetHealth() {
		return read<int>(data + HEALTH);
	}

	inline FVector GetLocation() {
		return read<FVector>(data + LOCATION);
	}

	inline FRotator GetRotation() {
		return read<FRotator>(data + ROTATION);
	}

	inline FVector GetVelocity() {
		return read<FVector>(data + VELOCITY);
	}

	inline APlayerReplicationInfo GetPlayerReplicationInfo() {
		return read<APlayerReplicationInfo>(data + PLAYER_REPLICATION_INFO);
	}

	inline APawn GetNextPawn() {
		return read<APawn>(data + NEXT_PAWN);
	}

	inline float GetEyeHeight() {
		return read<float>(data + BASE_EYE_HEIGHT);
	}

	inline USkeletalMeshComponent GetMesh() {
		return read<USkeletalMeshComponent>(data + MESH);
	}

	inline void SetGlowhack(bool isGlowing) {
		auto offset = data + GLOW;
		auto current = read<unsigned long>(offset);
		if(isGlowing) {
			current |= (1u << 17);
		}
		else {
			current &= ~(1u << 17);
		}
		write(offset, current);
	}

	uint64_t data;
};

class ACamera {
public:
	inline float GetDeafultFov() {
		return read<float>(data + DEAFULT_FOV);
	}

	inline FVector GetRealLocation() {
		return read<FVector>(data + REAL_LOCATION);
	}

	uint64_t data;
};

class AWorldInfo {
public:
	inline float GetTimeSeconds() {
		return read<float>(data + TIMESECONDS);
	}

	inline APawn GetPawnList() {
		return read<APawn>(data + PAWN_LIST);
	}

	uint64_t data;
};

class APlayerController {
public:
	inline FRotator GetRotation() {
		return read<FRotator>(data + ROTATION);
	}

	inline void SetRotation(FRotator rotation) {
		write(data + ROTATION, rotation);
	}

	inline float GetFovMultiplier() {
		return read<float>(data + PLAYER_FOV_MULTIPLIER);
	}

	inline APawn GetAcknowledgedPawn() {
		return read<APawn>(data + ACKNOWLEDGEDPAWN);
	}

	inline ACamera GetCamera() {
		return read<ACamera>(data + CAMERA);
	}

	inline AWorldInfo GetWorldInfo() {
		return read<AWorldInfo>(data + WORLD_INFO);
	}

	uint64_t data;
};

class ULocalPlayer {
public:
	inline APlayerController GetController() {
		return read<APlayerController>(data + CONTROLLER);
	}

	uint64_t data;
};

class UEngine {
public:
	inline ULocalPlayer GetLocalPlayer() {
		return read<ULocalPlayer>(read<uint64_t>(data + LOCALPLAYER));
	}

	uint64_t data;
};


UEngine GetUEngine(uint64_t base) {
	return read<UEngine>(base + ENGINE);
}