#if !defined(AFX_FEMMEVIEW_H__9D980E92_AF25_49AD_94B8_5FC96599FC59__INCLUDED_)
#define AFX_FEMMEVIEW_H__9D980E92_AF25_49AD_94B8_5FC96599FC59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FemmeView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFemmeView view

class CFemmeView : public CView {
  protected:
  CFemmeView(); // protected constructor used by dynamic creation
  DECLARE_DYNCREATE(CFemmeView)

  // Attributes
  public:
  CFemmeDoc* GetDocument();
  void ScreenToDwg(int xs, int ys, double* xd, double* yd, RECT* r);
  BOOL DwgToScreen(double xd, double yd, int* xs, int* ys, RECT* r);
  void DrawPSLG();
  void EnterPoint();
  BOOL ScanPreferences();
  BOOL WritePreferences();
  void OnNewDocument();
  void CheckIt();

  int EditAction; // tells if operating on points, lines, or blox
  double mx, my; // location of the mouse in model coordinates
  double ox, oy, mag; // location of lower left corner & scaling factor
  CStatusBar* StatBar; // pointer to the main window's status bar
  double GridSize; // size of each block in the grid
  BOOL GridFlag; // Flag telling whether or not to show grid
  BOOL SnapFlag;
  BOOL MeshFlag;
  BOOL ShowNames;
  BOOL MeshUpToDate;
  int FirstPoint;
  int ZoomWndFlag;
  int SelectWndFlag;
  int SelectCircFlag;
  int CreateRadiusFlag;
  double wzx, wzy;
  int placingNode;
  double MaxSeg, ArcAngle;
  double rmbStartX, rmbStartY;
  double rmbAreaSelection;
  int autoConnect;

  BOOL UiTweaks;

  // Colors used to render the view
  COLORREF SelColor;
  COLORREF MeshColor;
  COLORREF BlockColor;
  COLORREF LineColor;
  COLORREF GridColor;
  COLORREF BackColor;
  COLORREF NodeColor;
  COLORREF NameColor;

  // default view properties
  int d_action; //=0;
  double d_mag; //=100.;
  double d_gridsize; //=0.25;
  BOOL d_showgrid; //=TRUE;
  BOOL d_snapgrid; //=FALSE;
  BOOL d_showorigin;
  BOOL d_shownames;
  BOOL d_uitweaks;

  CString BinDir; // pathname for other FEMM executables
  CArray<CZPix, CZPix&> ZoomPix;

  // Operations
  public:
  // Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CFemmeView)
  public:
  virtual void OnDraw(CDC* pDC); // overridden to draw this view
  virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
  virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

  protected:
  virtual void OnInitialUpdate(); // called first time after construct
  virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
  virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
  virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
  virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
  //}}AFX_VIRTUAL

  // Implementation
  public:
  void lua_zoomin();
  void lua_zoomout();
  void lua_zoomnatural();
  void lnu_show_mesh();
  void lnu_purge_mesh();
  void lnuMakeMesh();
  void lnu_analyze(int bShow);

  void MyMoveTo(CDC* pDC, int x, int y);
  void MyLineTo(CDC* pDC, int x, int y);
  BOOL GetBoundingBox(double* x, double* y);

  virtual ~CFemmeView();
#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

  protected:
  // Generated message map functions
  protected:
  //{{AFX_MSG(CFemmeView)
  afx_msg void OnNodeOp();
  afx_msg void OnSegmentOp();
  afx_msg void OnBlockOp();
  afx_msg void OnMouseMove(UINT nFlags, CPoint point);
  afx_msg BOOL OnMouseWheel(UINT nFlags, short delta, CPoint point);
  afx_msg void OnZoomIn();
  afx_msg void OnZoomOut();
  afx_msg void OnShowGrid();
  afx_msg void OnSetGrid();
  afx_msg void OnSnapGrid();
  afx_msg void OnShowMesh();
  afx_msg void OnEditCopy();
  afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
  afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
  afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
  afx_msg void OnZoomNatural();
  afx_msg void OnZoomWnd();
  afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
  afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
  afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
  afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
  afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
  afx_msg void OnMakeMesh();
  afx_msg void OnMenuAnalyze();
  afx_msg void OnMenuViewres();
  afx_msg void OnArcsegOp();
  afx_msg void OnUndo();
  afx_msg void OnKbdZoom();
  afx_msg void OnMoveObjects();
  afx_msg void OnCopyObjects();
  afx_msg void OnDxfin();
  afx_msg void OnPurgemesh();
  afx_msg void OnDxfwrite();
  afx_msg void OnSelectwnd();
  afx_msg BOOL OnEraseBkgnd(CDC* pDC);
  afx_msg void OnPanDown();
  afx_msg void OnPanLeft();
  afx_msg void OnPanRight();
  afx_msg void OnPanUp();
  afx_msg void OnMenuMatlib();
  afx_msg void OnGroupOp();
  afx_msg void OnOpenSelected();
  afx_msg void OnEditScale();
  afx_msg void OnEditMirror();
  afx_msg void OnEditCut();
  afx_msg void OnEditCopyAsMetafile();
  afx_msg void OnViewShownames();
  afx_msg void OnViewUiTweaks();
  afx_msg void OnFDSelectCirc();
  afx_msg void OnViewShowOrphans();
  afx_msg void OnCreateRadius();
  afx_msg void OnUpdateEditExterior(CCmdUI* pCmdUI);
  afx_msg void OnMakeABC();
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
  public:
};

#ifndef _DEBUG // debug version in femmeView.cpp
inline CFemmeDoc* CFemmeView::GetDocument()
{
  return (CFemmeDoc*)m_pDocument;
}
#endif

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FEMMEVIEW_H__9D980E92_AF25_49AD_94B8_5FC96599FC59__INCLUDED_)
