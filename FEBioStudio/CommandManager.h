#pragma once
#include "Command.h"
#include <stack>

class CDocument;

typedef std::stack<CCommand*> CCmdStack;

class CBasicCmdManager
{
public:
	CBasicCmdManager();
	virtual ~CBasicCmdManager();

	bool CanUndo() { return (m_Undo.size() > 0); }
	bool CanRedo() { return (m_Redo.size() > 0); }

	void AddCommand(CCommand* pcmd);

	virtual bool DoCommand(CCommand* pcmd);

	virtual void UndoCommand();

	virtual void RedoCommand();

	void Clear();

	const char* GetUndoCmdName() { return (m_Undo.size() ? m_Undo.top()->GetName() : 0); }
	const char* GetRedoCmdName() { return (m_Redo.size() ? m_Redo.top()->GetName() : 0); }

protected:
	CCmdStack	m_Undo;	// the undo stack
	CCmdStack	m_Redo;	// the redo stack

public:
	static const std::string& GetErrorString() { return m_err; }
	void SetErrorString(const std::string& err) { m_err = err; }
	static std::string	m_err;	// error string
};

class CCommandManager  : public CBasicCmdManager
{
public:
	CCommandManager(CDocument* pdoc);
	virtual ~CCommandManager();

	bool DoCommand(CCommand* pcmd) override;

	void UndoCommand() override;

	void RedoCommand() override;

protected:
	CDocument* m_pDoc; // pointer to the current document
};
