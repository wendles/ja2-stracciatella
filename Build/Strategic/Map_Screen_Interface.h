#ifndef MAP_SCREEN_INTERFACE_H
#define MAP_SCREEN_INTERFACE_H

#include "Item_Types.h"
#include "JA2Types.h"
#include "MessageBoxScreen.h"


// char breath and life position
#define BAR_INFO_X 66
#define BAR_INFO_Y 61

// merc icon position
#define CHAR_ICON_CONTRACT_Y 64
#define CHAR_ICON_X 187
#define CHAR_ICON_WIDTH 10
#define CHAR_ICON_HEIGHT 10
#define CHAR_ICON_SPACING 13

// max number of characters
//Character List Length
#define MAX_CHARACTER_COUNT 20

// map screen font
#define MAP_SCREEN_FONT BLOCKFONT2

// characterlist regions
#define     Y_START               146
#define			MAP_START_KEYRING_Y   107
#define     Y_SIZE                GetFontHeight(MAP_SCREEN_FONT)


// attribute menu defines (must match NUM_TRAINABLE_STATS defines, and pAttributeMenuStrings )
enum {
	ATTRIB_MENU_STR=0,
	ATTRIB_MENU_DEX,
	ATTRIB_MENU_AGI,
	ATTRIB_MENU_HEA,
	ATTRIB_MENU_MARK,
	ATTRIB_MENU_MED,
	ATTRIB_MENU_MECH,
	ATTRIB_MENU_LEAD,
	ATTRIB_MENU_EXPLOS,
	ATTRIB_MENU_CANCEL,
	MAX_ATTRIBUTE_STRING_COUNT,
};

// the epc assignment menu
enum{
	EPC_MENU_ON_DUTY = 0,
	EPC_MENU_PATIENT,
	EPC_MENU_VEHICLE,
	EPC_MENU_REMOVE,
	EPC_MENU_CANCEL,
	MAX_EPC_MENU_STRING_COUNT,
};

// assignment menu defines
enum {
	ASSIGN_MENU_ON_DUTY=0,
	ASSIGN_MENU_DOCTOR,
	ASSIGN_MENU_PATIENT,
	ASSIGN_MENU_VEHICLE,
	ASSIGN_MENU_REPAIR,
	ASSIGN_MENU_TRAIN,
	ASSIGN_MENU_CANCEL,
	MAX_ASSIGN_STRING_COUNT,
};


// training assignment menu defines
enum {
	TRAIN_MENU_SELF,
	TRAIN_MENU_TOWN,
	TRAIN_MENU_TEAMMATES,
	TRAIN_MENU_TRAIN_BY_OTHER,
	TRAIN_MENU_CANCEL,
	MAX_TRAIN_STRING_COUNT,
};


// the remove merc from team pop up box strings
enum{
	REMOVE_MERC = 0,
	REMOVE_MERC_CANCEL,
	MAX_REMOVE_MERC_COUNT,
};


// squad menu defines
enum{
	SQUAD_MENU_1,
	SQUAD_MENU_2,
	SQUAD_MENU_3,
	SQUAD_MENU_4,
	SQUAD_MENU_5,
	SQUAD_MENU_6,
	SQUAD_MENU_7,
	SQUAD_MENU_8,
	SQUAD_MENU_9,
	SQUAD_MENU_10,
	SQUAD_MENU_11,
	SQUAD_MENU_12,
	SQUAD_MENU_13,
	SQUAD_MENU_14,
	SQUAD_MENU_15,
	SQUAD_MENU_16,
	SQUAD_MENU_17,
	SQUAD_MENU_18,
	SQUAD_MENU_19,
	SQUAD_MENU_20,
	SQUAD_MENU_CANCEL,
	MAX_SQUAD_MENU_STRING_COUNT,
};


// contract menu defines
enum{
	CONTRACT_MENU_CURRENT_FUNDS = 0,
	CONTRACT_MENU_SPACE,
	CONTRACT_MENU_DAY,
	CONTRACT_MENU_WEEK,
	CONTRACT_MENU_TWO_WEEKS,
	CONTRACT_MENU_TERMINATE,
	CONTRACT_MENU_CANCEL,
	MAX_CONTRACT_MENU_STRING_COUNT,
};

// enums for pre battle interface pop ups
enum
{
	ASSIGNMENT_POPUP,
	DESTINATION_POPUP,
	CONTRACT_POPUP
};


enum{
	NO_REASON_FOR_UPDATE = 0,
	CONTRACT_FINISHED_FOR_UPDATE,
	ASSIGNMENT_FINISHED_FOR_UPDATE,
	ASSIGNMENT_RETURNING_FOR_UPDATE,
	ASLEEP_GOING_AUTO_FOR_UPDATE,
	CONTRACT_EXPIRE_WARNING_REASON,
};


enum{
	START_RED_SECTOR_LOCATOR = 0,
	STOP_RED_SECTOR_LOCATOR,
	START_YELLOW_SECTOR_LOCATOR,
	STOP_YELLOW_SECTOR_LOCATOR,
};


// dimensions and offset for merc update box
#define UPDATE_MERC_FACE_X_WIDTH 50
#define UPDATE_MERC_FACE_X_HEIGHT 50
#define UPDATE_MERC_FACE_X_OFFSET 2
#define UPDATE_MERC_FACE_Y_OFFSET 2
#define WIDTH_OF_UPDATE_PANEL_BLOCKS  50
#define HEIGHT_OF_UPDATE_PANEL_BLOCKS 50
#define UPDATE_MERC_Y_OFFSET 4
#define UPDATE_MERC_X_OFFSET 4


// dimensions and offset for merc update box
#define TACT_UPDATE_MERC_FACE_X_WIDTH 70
#define TACT_UPDATE_MERC_FACE_X_HEIGHT 49
#define TACT_UPDATE_MERC_FACE_X_OFFSET 8
#define TACT_UPDATE_MERC_FACE_Y_OFFSET 6
#define TACT_WIDTH_OF_UPDATE_PANEL_BLOCKS  70
#define TACT_HEIGHT_OF_UPDATE_PANEL_BLOCKS 49
#define TACT_UPDATE_MERC_Y_OFFSET 4
#define TACT_UPDATE_MERC_X_OFFSET 4


// the first vehicle slot int he list
#define FIRST_VEHICLE 18


extern BOOLEAN fShowAssignmentMenu;
extern BOOLEAN fShowTrainingMenu ;
extern BOOLEAN fShowAttributeMenu;
extern BOOLEAN fShowSquadMenu ;
extern BOOLEAN fShowContractMenu ;
extern BOOLEAN fShowRemoveMenu ;

extern BOOLEAN fLockOutMapScreenInterface;

// The character data structure
typedef struct MapScreenCharacterSt
{
	SOLDIERTYPE* merc;
	PathSt*      prev_path;
	BOOLEAN      selected;
} MapScreenCharacterSt;


// map screen character structure list, contrains soldier ids into menptr
extern MapScreenCharacterSt gCharactersList[ ];


// map inventory pool inited
extern BOOLEAN fMapInventoryPoolInited;

// highlighted lines
extern INT32 giHighLine;
extern INT32 giAssignHighLine;
extern INT32 giDestHighLine;
extern INT32 giContractHighLine;
extern INT32 giSleepHighLine;

extern SGPVObject* guiUpdatePanelTactical;
extern BOOLEAN fShowUpdateBox;

extern SGPPoint ContractPosition;
extern SGPPoint AttributePosition;
extern SGPPoint TrainPosition;
extern SGPPoint VehiclePosition;
extern SGPPoint AssignmentPosition ;
extern SGPPoint SquadPosition ;

extern SGPPoint RepairPosition;

extern SGPPoint OrigContractPosition;
extern SGPPoint OrigAttributePosition;
extern SGPPoint OrigSquadPosition ;
extern SGPPoint OrigAssignmentPosition ;
extern SGPPoint OrigTrainPosition;
extern SGPPoint OrigVehiclePosition;

// disble team info panel due to showing of battle roster
extern BOOLEAN fDisableDueToBattleRoster;

extern BOOLEAN gfAtLeastOneMercWasHired;

// curtrent map sector z that is being displayed in the mapscreen
extern INT32 iCurrentMapSectorZ;

// y position of the pop up box
extern INT32 giBoxY;

// pop up box textures
extern SGPVSurface* guiPOPUPTEX;
extern SGPVObject* guiPOPUPBORDERS;

// the level-changing markers on the map border
extern SGPVObject* guiLEVELMARKER;

// the currently selected character arrow
extern SGPVObject* guiSelectedCharArrow;

#ifndef JA2DEMO
// sam and mine icons
extern SGPVObject* guiSAMICON;
#endif

extern BOOLEAN fShowMapScreenMovementList;

// do we need to rebuild the mapscreen characterlist?
extern BOOLEAN fReBuildCharacterList;

// restore glow rotation in contract region glow boxes
extern BOOLEAN fResetContractGlow;

// init vehicle and characters list
void InitalizeVehicleAndCharacterList( void );

// set this entry to as selected
void SetEntryInSelectedCharacterList( INT8 bEntry );
// set this entry to as unselected
void ResetEntryForSelectedList( INT8 bEntry );

// reset selected list
void ResetSelectedListForMapScreen(void);

// build a selected list from a to b, inclusive
void BuildSelectedListFromAToB( INT8 bA, INT8 bB );

// isa this entry int he selected character list set?
BOOLEAN IsEntryInSelectedListSet( INT8 bEntry );

// is there more than one person selected?
BOOLEAN MultipleCharacterListEntriesSelected( void );

// toggle this entry on or off
void ToggleEntryInSelectedList( INT8 bEntry );

// reset assignments for mercs on selected list who have this assignment
void ResetAssignmentsForMercsTrainingUnpaidSectorsInSelectedList(INT8 bAssignment);

void RestoreBackgroundForAssignmentGlowRegionList( void );
void RestoreBackgroundForDestinationGlowRegionList( void );
void RestoreBackgroundForContractGlowRegionList( void );
void RestoreBackgroundForSleepGlowRegionList( void );

// play click when we are entering a glow region
void PlayGlowRegionSound( void );

// is this character in the action of plotting a path?
INT16 CharacterIsGettingPathPlotted( INT16 sCharNumber );

// disable team info panels
void DisableTeamInfoPanels( void );

// enable team info panels
void EnableTeamInfoPanels( void );

// activate pop up for soldiers in the pre battle interface
void ActivateSoldierPopup( SOLDIERTYPE *pSoldier, UINT8 ubPopupType, INT16 xp, INT16 yp );

// do mapscreen message box
INT32 DoMapMessageBox( UINT8 ubStyle, const wchar_t *zString, UINT32 uiExitScreen, UINT16 usFlags, MSGBOX_CALLBACK ReturnCallback );

// hop up one leve,l int he map screen level interface
void GoUpOneLevelInMap( void );

// go down one level in the mapscreen map interface
void GoDownOneLevelInMap( void );

// jump to this level on the map
void JumpToLevel( INT32 iLevel );

// check to see if we need to update the screen
void CheckAndUpdateBasedOnContractTimes( void );

// check if are just about to display this pop up or stopping display
void HandleDisplayOfItemPopUpForSector( INT16 sMapX, INT16 sMapY, INT16 sMapZ );

// display red arrow by name of selected merc
void HandleDisplayOfSelectedMercArrows( void );

// check which guys can move with this guy
void DeselectSelectedListMercsWhoCantMoveWithThisGuy(const SOLDIERTYPE* s);

// get morale string for this grunt given this morale level
const wchar_t* GetMoraleString(const SOLDIERTYPE* pSoldier);

// handle leaving of equipment in sector
void HandleLeavingOfEquipmentInCurrentSector(SOLDIERTYPE* s);

// set up a linked list of items being dropped and post an event to later drop them
void HandleMercLeavingEquipmentInDrassen(SOLDIERTYPE* s);
void HandleMercLeavingEquipmentInOmerta(SOLDIERTYPE* s);

// actually drop the stored list of items
void HandleEquipmentLeftInOmerta( UINT32 uiSlotIndex );
void HandleEquipmentLeftInDrassen( UINT32 uiSlotIndex );

// init/shutdown leave item lists
void InitLeaveList( void );
void ShutDownLeaveList( void );

// add item to leave equip index
BOOLEAN AddItemToLeaveIndex( OBJECTTYPE *o, UINT32 uiIndex );

// handle a group about to arrive in a sector
void HandleGroupAboutToArrive( void );


// create and destroy the status bars mouse region
void CreateMapStatusBarsRegion( void );
void RemoveMapStatusBarsRegion( void );
void UpdateCharRegionHelpText( void );

// find this soldier in mapscreen character list and set as contract
void FindAndSetThisContractSoldier( SOLDIERTYPE *pSoldier );

// lose the cursor, re-render
void HandleMAPUILoseCursorFromOtherScreen( void );

void RenderMapRegionBackground( void );

// update mapscreen assignment positions
void UpdateMapScreenAssignmentPositions( void );

// get the umber of valid mercs in the mapscreen character list
INT32 GetNumberOfPeopleInCharacterList( void );

// the next and previous people in the mapscreen
void GoToPrevCharacterInList( void );
void GoToNextCharacterInList( void );

// this does the whole miner giving player info speil
void HandleMinerEvent( UINT8 bMinerNumber, INT16 sSectorX, INT16 sSectorY, INT16 sQuoteNumber, BOOLEAN fForceMapscreen );

// set up the event of animating a mine sector
void SetUpAnimationOfMineSectors( INT32 iEvent );

void TurnOnSectorLocator( UINT8 ubProfileID );
void TurnOffSectorLocator(void);

extern INT16 gsSectorLocatorX;
extern INT16 gsSectorLocatorY;
extern UINT8 gubBlitSectorLocatorCode;

enum
{
	LOCATOR_COLOR_NONE,
	LOCATOR_COLOR_RED,
	LOCATOR_COLOR_YELLOW
};

extern SGPVObject* guiSectorLocatorGraphicID;
void HandleBlitOfSectorLocatorIcon( INT16 sSectorX, INT16 sSectorY, INT16 sSectorZ, UINT8 ubLocatorID );


// the tactical version

// handle the actual showingof the list
void HandleShowingOfTacticalInterfaceFastHelpText( void );

// start showing the list
void StartShowingInterfaceFastHelpText( void );

// is the list active?
BOOLEAN IsTheInterfaceFastHelpTextActive( void );

/* This will setup a fast help text region that is unrelated to mouse regions.
 * The user is to pass in the x,y position of the box, the width to wrap the
 * string and the string itself */
void SetUpFastHelpRegion(INT32 x, INT32 y, INT32 width, const wchar_t* text);


// reset assignment for mercs trainign militia in this sector
void ResetAssignmentOfMercsThatWereTrainingMilitiaInThisSector( INT16 sSectorX, INT16 sSectorY );


// the sector move box
void CreateDestroyMovementBox( INT16 sSectorX, INT16 sSectorY, INT16 sSectorZ );
void SetUpMovingListsForSector( INT16 sSectorX, INT16 sSectorY, INT16 sSectorZ );
void ReBuildMoveBox( void );
BOOLEAN IsCharacterSelectedForAssignment( INT16 sCharNumber );
BOOLEAN IsCharacterSelectedForSleep( INT16 sCharNumber );

// the update box
void CreateDestroyTheUpdateBox( void );
void SetSoldierUpdateBoxReason( INT32 iReason );
void AddSoldierToUpdateBox( SOLDIERTYPE *pSoldier );
void DisplaySoldierUpdateBox(void);


void SetUpdateBoxFlag( BOOLEAN fFlag );


/// set the town of Tixa as found by the player
void SetTixaAsFound( void );

// set the town of Orta as found by the player
void SetOrtaAsFound( void );

// set this SAM site as being found by the player
void SetSAMSiteAsFound( UINT8 uiSamIndex );

// init time menus
void InitTimersForMoveMenuMouseRegions( void );

// the screen mask
void CreateScreenMaskForMoveBox( void );
void RemoveScreenMaskForMoveBox( void );


// help text to show user merc has insurance
void UpdateHelpTextForMapScreenMercIcons( void );
void CreateDestroyInsuranceMouseRegionForMercs( BOOLEAN fCreate );


// stuff to deal with player just starting the game
BOOLEAN HandleTimeCompressWithTeamJackedInAndGearedToGo( void );

// handle sector being taken over uncontested
BOOLEAN NotifyPlayerWhenEnemyTakesControlOfImportantSector( INT16 sSectorX, INT16 sSectorY, INT8 bSectorZ, BOOLEAN fContested );

// handle notifying player of invasion by enemy
void NotifyPlayerOfInvasionByEnemyForces( INT16 sSectorX, INT16 sSectorY, INT8 bSectorZ, MSGBOX_CALLBACK ReturnCallback );

void ShutDownUserDefineHelpTextRegions( void );

// shwo the update box
void ShowUpdateBox( void );

// add special events
void AddSoldierToWaitingListQueue(const SOLDIERTYPE* s);
void AddReasonToWaitingListQueue( INT32 iReason );
void AddDisplayBoxToWaitingQueue( void );

typedef enum MoveError
{
	ME_CUSTOM          = -99,
	ME_OK              =   0,
	ME_UNDERGROUND     =   1,
	ME_ENEMY           =   2,
	ME_BUSY            =   3,
	ME_POW             =   5,
	ME_TRANSIT         =   8,
	ME_AIR_RAID        =  10,
	ME_COMBAT          =  11,
	ME_VEHICLE_EMPTY   =  32,
	ME_MUSEUM          =  34,
	ME_VEHICLE_NO_GAS  =  42,
	ME_VEHICLE_DAMAGED =  47,
	ME_ROBOT_ALONE     =  49
} MoveError;

// can this group move it out
MoveError CanEntireMovementGroupMercIsInMove(SOLDIERTYPE*);
void ReportMapScreenMovementError( INT8 bErrorNumber );

void HandleRebuildingOfMapScreenCharacterList( void );

void RequestToggleTimeCompression( void );
void RequestIncreaseInTimeCompression( void );
void RequestDecreaseInTimeCompression( void );

void SelectUnselectedMercsWhoMustMoveWithThisGuy( void );

BOOLEAN LoadLeaveItemList( HWFILE hFile );
BOOLEAN SaveLeaveItemList( HWFILE hFile );

BOOLEAN CheckIfSalaryIncreasedAndSayQuote( SOLDIERTYPE *pSoldier, BOOLEAN fTriggerContractMenu );

void EndUpdateBox( BOOLEAN fContinueTimeCompression );

BOOLEAN MapscreenCanPassItemToChar(const SOLDIERTYPE*);

INT32 GetNumberOfMercsInUpdateList(void);

extern MOUSE_REGION gMapStatusBarsRegion;

#endif
