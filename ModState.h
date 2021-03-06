#ifndef __MODSTATE_H__
#define __MODSTATE_H__
#include "JMDefs.h"
#include "StateBase.h"

class CModState;
typedef int (CModState::*KeyHandler)(SDL_Keysym *keysym);
enum eModifier
{
	MOD_INVALID=-1,
	MOD_OPEN=0,
	MOD_TUNNEL=1,
	MOD_INIT,
	MOD_CLOSE,
	MOD_MAX
};

class CModState : public CStateBase
{
	// Member Variables
public:
protected:
	char m_cCommand;
	JVector m_vNewPos;
private:
	
	// Member Functions
public:
	CModState();
	~CModState() {};


	virtual void OnUpdate() {};
	virtual int OnBaseHandleKey( SDL_Keysym *keysym );
	virtual int OnHandleKey( SDL_Keysym *keysym );
protected:
	bool	IsDirectional(SDL_Keysym *keysym);
	void	GetDir(SDL_Keysym *keysym, JVector &vDir);
	
private:
	KeyHandler	m_pKeyHandlers[MOD_MAX];
	KeyHandler	m_pCurKeyHandler;

	eModifier	m_eCurModifier;

	int OnHandleOpen( SDL_Keysym *keysym );
	int OnHandleTunnel( SDL_Keysym *keysym );
	int OnHandleClose( SDL_Keysym *keysym );
	int OnHandleInit( SDL_Keysym *keysym );


	bool TestOpen();
	bool DoOpen();

	bool TestTunnel();
	bool DoTunnel();	

	bool TestClose();
	bool DoClose();
	
	void	ResetToState( int newstate );
};

#endif // __MODSTATE_H__