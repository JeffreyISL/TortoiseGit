// TortoiseGit - a Windows shell extension for easy version control

// Copyright (C) 2020 - TortoiseGit

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//

#include "stdafx.h"
#include "TortoiseGitBlame.h"
#include "CTGitMFCVisualManager.h"
#include "Theme.h"
#include <afxcustomizebutton.h>

IMPLEMENT_DYNCREATE(CTGitMFCVisualManager, CMFCVisualManagerOffice2007)

CTGitMFCVisualManager::CTGitMFCVisualManager()
{
	SetStyle(CMFCVisualManagerOffice2007::Office2007_ObsidianBlack);
}

CTGitMFCVisualManager::~CTGitMFCVisualManager()
{
}

void CTGitMFCVisualManager::OnUpdateSystemColors()
{
	__super::OnUpdateSystemColors();

	m_clrMenuText = CTheme::darkTextColor;
	m_clrMenuTextDisabled = CTheme::darkDisabledTextColor;
	m_clrMenuLight = CTheme::darkBkColor;
	m_brMenuLight.DeleteObject();
	m_brMenuLight.CreateSolidBrush(m_clrMenuLight);

	m_clrBarGradientLight = CTheme::darkBkColor;
	m_clrBarGradientDark = m_clrBarGradientLight;
	m_clrMenuBarGradientLight = CTheme::darkBkColor;
	m_clrMenuBarGradientDark = CTheme::darkBkColor;
	m_clrMenuBarGradientVertLight = m_clrMenuBarGradientLight;
	m_clrMenuBarGradientVertDark = m_clrMenuBarGradientDark;

	m_clrToolBarGradientDark = m_clrToolBarGradientLight = CTheme::darkBkColor;

	m_clrSeparator2 = CTheme::darkBkColor;
	m_penSeparator2.DeleteObject();
	m_penSeparator2.CreatePen(PS_SOLID, 0, m_clrSeparator2);

	GetGlobalData()->brHilite.DeleteObject();
	GetGlobalData()->brHilite.CreateSolidBrush(RGB(65, 65, 65));
}

void CTGitMFCVisualManager::OnHighlightMenuItem(CDC* pDC, CMFCToolBarMenuButton* pButton, CRect rect, COLORREF& clrText)
{
	CMFCVisualManager::OnHighlightMenuItem(pDC, pButton, rect, clrText);
}

void CTGitMFCVisualManager::OnDrawMenuCheck(CDC* pDC, CMFCToolBarMenuButton* pButton, CRect rect, BOOL bHighlight, BOOL bIsRadio)
{
	CMFCVisualManager::OnDrawMenuCheck(pDC, pButton, rect, bHighlight, bIsRadio);
}

BOOL CTGitMFCVisualManager::IsOwnerDrawMenuCheck()
{
	return FALSE;
}

void CTGitMFCVisualManager::OnFillBarBackground(CDC* pDC, CBasePane* pBar, CRect rectClient, CRect rectClip, BOOL bNCArea)
{
	// don't paint vertical lines on menus
	if (pBar->IsKindOf(RUNTIME_CLASS(CMFCPopupMenuBar)))
	{
		pDC->FillRect(rectClip, &m_brMenuLight);
		return;
	}

	__super::OnFillBarBackground(pDC, pBar, rectClient, rectClip, bNCArea);
}
