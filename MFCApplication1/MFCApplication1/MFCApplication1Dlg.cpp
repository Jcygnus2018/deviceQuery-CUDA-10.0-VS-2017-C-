
// MFCApplication1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	m_list1.ResetContent();
	m_genericstr = "";

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Program main from deviceQuery  C:\CPP\CUDA Samples\v10.0\1_Utilities\deviceQuery
//
// unicode, x64 only, Debug and Release
///////////////////////////////////////////////////////////////////////////////////////////////////
//int main(int argc, char **argv) {
//	pArgc = &argc;
//	pArgv = argv;
//
//	printf("%s Starting...\n\n", argv[0]);
//	printf(
//		" CUDA Device Query (Runtime API) version (CUDART static linking)\n\n");
//
//	int deviceCount = 0;
//	cudaError_t error_id = cudaGetDeviceCount(&deviceCount);
//
//	.
//	.
//	.
//  
//  I removed the printf so output doesn't go to stdout. This project deos not have a console.
//  Instead, I used a CString ( m_genericstr ) and CListBox ( m_list1 ) to facilitate having
//  the output be added to a list box. I also removed the
//  pArgc = &argc;
//  pArgv = argv;
//  and changed a few things in small ways to make the output presentable,
//  like using _T("ascii string") to be able to have unicode.
//
//  All other changes were in the includes, libraries, additional dependencies
//  and MTD - type stuff....  
//  To be honest, I am not well-versed in linkages, compiler switches and such.
///////////////////////////////////////////////////////////////////////////////////////////////////

void CMFCApplication1Dlg::OnBnClickedButton1()
{
	m_list1.ResetContent();
	
	m_genericstr.Format(_T("%s Starting "), _T("GTX 750"));
	m_list1.AddString((LPCTSTR)m_genericstr);

	m_genericstr = " CUDA Device Query (Runtime API) version (CUDART static linking)";
	m_list1.AddString((LPCTSTR)m_genericstr);
////	printf("%s Starting...\n\n", argv[0]);
////	printf(" CUDA Device Query (Runtime API) version (CUDART static linking)\n\n");

	int deviceCount = 0;
	cudaError_t error_id = cudaGetDeviceCount(&deviceCount);

	if (error_id != cudaSuccess)
	{
		m_genericstr.Format(_T("cudaGetDeviceCount returned %d -> %s "), static_cast<int>(error_id), cudaGetErrorString(error_id));
		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("cudaGetDeviceCount returned %d\n-> %s\n",
////			static_cast<int>(error_id), cudaGetErrorString(error_id));

		m_genericstr = "Result = FAIL";
		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("Result = FAIL\n");
////	exit(EXIT_FAILURE);  // no exit, void function
	}

	// This function call returns 0 if there are no CUDA capable devices.
	if (deviceCount == 0)
	{
		m_genericstr = "There are no available device(s) that support CUDA";
		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("There are no available device(s) that support CUDA\n");

	}
	else
	{
		m_genericstr.Format(_T("Detected %d CUDA Capable device(s)"), deviceCount);
		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("Detected %d CUDA Capable device(s)\n", deviceCount);

	}

	int dev, driverVersion = 0, runtimeVersion = 0;

	for (dev = 0; dev < deviceCount; ++dev)
	{
		cudaSetDevice(dev);
		cudaDeviceProp deviceProp;
		cudaGetDeviceProperties(&deviceProp, dev);

		m_genericstr.Format(_T("Device %d: \"%S\""), dev, deviceProp.name );
		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("\nDevice %d: \"%s\"\n", dev, deviceProp.name);


		// Console log
		cudaDriverGetVersion(&driverVersion);
		cudaRuntimeGetVersion(&runtimeVersion);
		
		m_genericstr.Format(_T("  CUDA Driver Version / Runtime Version          %d.%d / %d.%d"),
						driverVersion / 1000, (driverVersion % 100) / 10,
						runtimeVersion / 1000, (runtimeVersion % 100) / 10);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  CUDA Driver Version / Runtime Version          %d.%d / %d.%d\n",
////			driverVersion / 1000, (driverVersion % 100) / 10,
////			runtimeVersion / 1000, (runtimeVersion % 100) / 10);


		m_genericstr.Format(_T("  CUDA Capability Major/Minor version number:    %d.%d"),
						deviceProp.major, deviceProp.minor);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  CUDA Capability Major/Minor version number:    %d.%d\n",
////			deviceProp.major, deviceProp.minor);


////		char msg[256];  // not used, so commented out
		// a bit of trouble here with _int64 types, 
		// so I put in jrkk and irkk to debug, and decided to use them.
		// might have to go to double for higher memory than the GTX 750

		double jrkk;
		double irkk;
		jrkk = (float)deviceProp.totalGlobalMem;
		irkk = jrkk / 1048576;

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)

		m_genericstr.Format(_T("  Total amount of global memory:                 %.0f MBytes (%.0f bytes)"),
			 irkk, jrkk);		
////		sprintf_s(msg, sizeof(msg),
////			"  Total amount of global memory:                 %.0f MBytes "
////			"(%llu bytes)\n",
////			static_cast<float>(deviceProp.totalGlobalMem / 1048576.0f),
////			(unsigned long long)deviceProp.totalGlobalMem);


#else

		m_genericstr.Format(_T("    Total amount of global memory:                 %.0f MBytes (%.0f bytes)"),
			irkk, jrkk;

////		snprintf(msg, sizeof(msg),
////			"  Total amount of global memory:                 %.0f MBytes "
////			"(%llu bytes)\n",
////			static_cast<float>(deviceProp.totalGlobalMem / 1048576.0f),
////			(unsigned long long)deviceProp.totalGlobalMem);

#endif
		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("%s", msg);


		m_genericstr.Format(_T("  (%2d) Multiprocessors, (%3d) CUDA Cores/MP:     %d CUDA Cores"),
			deviceProp.multiProcessorCount, _ConvertSMVer2Cores(deviceProp.major, deviceProp.minor),
			_ConvertSMVer2Cores(deviceProp.major, deviceProp.minor) *deviceProp.multiProcessorCount);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  (%2d) Multiprocessors, (%3d) CUDA Cores/MP:     %d CUDA Cores\n",
////			deviceProp.multiProcessorCount,
////			_ConvertSMVer2Cores(deviceProp.major, deviceProp.minor),
////			_ConvertSMVer2Cores(deviceProp.major, deviceProp.minor) *
////			deviceProp.multiProcessorCount);


		m_genericstr.Format(_T("  GPU Max Clock rate:                            %.0f MHz (%0.2f "),
			deviceProp.clockRate * 1e-3f, deviceProp.clockRate * 1e-6f);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf(
////			"  GPU Max Clock rate:                            %.0f MHz (%0.2f "
////			"GHz)\n",
////			deviceProp.clockRate * 1e-3f, deviceProp.clockRate * 1e-6f);


#if CUDART_VERSION >= 5000
		// This is supported in CUDA 5.0 (runtime API device properties)

		m_genericstr.Format(_T("  Memory Clock rate:                             %.0f Mhz"),
			deviceProp.memoryClockRate * 1e-3f);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Memory Clock rate:                             %.0f Mhz\n",
////			deviceProp.memoryClockRate * 1e-3f);


		m_genericstr.Format(_T("  Memory Bus Width:                              %d-bit"),
			deviceProp.memoryBusWidth);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Memory Bus Width:                              %d-bit\n",
////			deviceProp.memoryBusWidth);


		if (deviceProp.l2CacheSize) 
		{
			m_genericstr.Format(_T("  L2 Cache Size:                                 %d bytes"),
				deviceProp.l2CacheSize);

			m_list1.AddString((LPCTSTR)m_genericstr);
////			printf("  L2 Cache Size:                                 %d bytes\n",
////				deviceProp.l2CacheSize);

		}

#else
		// This only available in CUDA 4.0-4.2 (but these were only exposed in the
		// CUDA Driver API)
		int memoryClock;
		getCudaAttribute<int>(&memoryClock, CU_DEVICE_ATTRIBUTE_MEMORY_CLOCK_RATE,
			dev);

		m_genericstr.Format(_T("  Memory Clock rate:                             %.0f Mhz"),
			memoryClock * 1e-3f);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Memory Clock rate:                             %.0f Mhz\n",
////			memoryClock * 1e-3f);


		int memBusWidth;
		getCudaAttribute<int>(&memBusWidth,
			CU_DEVICE_ATTRIBUTE_GLOBAL_MEMORY_BUS_WIDTH, dev);

		m_genericstr.Format(_T("  Memory Bus Width:                              %d-bit"),
			memBusWidth);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Memory Bus Width:                              %d-bit\n",
////			memBusWidth);


		int L2CacheSize;
		getCudaAttribute<int>(&L2CacheSize, CU_DEVICE_ATTRIBUTE_L2_CACHE_SIZE, dev);

		if (L2CacheSize) 
		{
			m_genericstr.Format(_T("  L2 Cache Size:                                 %d bytes"),
				L2CacheSize);

			m_list1.AddString((LPCTSTR)m_genericstr);
////			printf("  L2 Cache Size:                                 %d bytes\n",
////				L2CacheSize);

		}

#endif

		m_genericstr.Format(_T("  Maximum Texture Dimension Size (x,y,z)         1D=(%d), 2D=(%d, %d), 3D = (%d, %d, %d)"),
			deviceProp.maxTexture1D, deviceProp.maxTexture2D[0],
			deviceProp.maxTexture2D[1], deviceProp.maxTexture3D[0],
			deviceProp.maxTexture3D[1], deviceProp.maxTexture3D[2]);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf(
////			"  Maximum Texture Dimension Size (x,y,z)         1D=(%d), 2D=(%d, "
////			"%d), 3D=(%d, %d, %d)\n",
////			deviceProp.maxTexture1D, deviceProp.maxTexture2D[0],
////			deviceProp.maxTexture2D[1], deviceProp.maxTexture3D[0],
////			deviceProp.maxTexture3D[1], deviceProp.maxTexture3D[2]);


		m_genericstr.Format(_T("  Maximum Layered 1D Texture Size, (num) layers  1D=(%d), %d layers"),
			deviceProp.maxTexture1DLayered[0], deviceProp.maxTexture1DLayered[1]);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf(
////			"  Maximum Layered 1D Texture Size, (num) layers  1D=(%d), %d layers\n",
////			deviceProp.maxTexture1DLayered[0], deviceProp.maxTexture1DLayered[1]);


		m_genericstr.Format(_T("  Maximum Layered 2D Texture Size, (num) layers  2D=(%d, %d), %d layers"),
			deviceProp.maxTexture2DLayered[0], deviceProp.maxTexture2DLayered[1],
			deviceProp.maxTexture2DLayered[2]);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf(
////			"  Maximum Layered 2D Texture Size, (num) layers  2D=(%d, %d), %d "
////			"layers\n",
////			deviceProp.maxTexture2DLayered[0], deviceProp.maxTexture2DLayered[1],
////			deviceProp.maxTexture2DLayered[2]);


		m_genericstr.Format(_T("  Total amount of constant memory:               %lu bytes"),
			deviceProp.totalConstMem);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Total amount of constant memory:               %lu bytes\n",
////			deviceProp.totalConstMem);


		m_genericstr.Format(_T("  Total amount of shared memory per block : %lu bytes"),
			deviceProp.sharedMemPerBlock);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Total amount of shared memory per block:       %lu bytes\n",
////			deviceProp.sharedMemPerBlock);


		m_genericstr.Format(_T("  Total number of registers available per block: %d"),
			deviceProp.regsPerBlock);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Total number of registers available per block: %d\n",
////			deviceProp.regsPerBlock);


		m_genericstr.Format(_T("  Warp size:                                     %d"),
			deviceProp.warpSize);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Warp size:                                     %d\n",
////			deviceProp.warpSize);


		m_genericstr.Format(_T("  Maximum number of threads per multiprocessor:  %d"),
			deviceProp.maxThreadsPerMultiProcessor);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Maximum number of threads per multiprocessor:  %d\n",
////			deviceProp.maxThreadsPerMultiProcessor);


		m_genericstr.Format(_T("  Maximum number of threads per block:           %d"),
			deviceProp.maxThreadsPerBlock);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Maximum number of threads per block:           %d\n",
////			deviceProp.maxThreadsPerBlock);


		m_genericstr.Format(_T("  Max dimension size of a thread block (x,y,z): (%d, %d, %d)"),
			deviceProp.maxThreadsDim[0], deviceProp.maxThreadsDim[1],
			deviceProp.maxThreadsDim[2]);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Max dimension size of a thread block (x,y,z): (%d, %d, %d)\n",
////			deviceProp.maxThreadsDim[0], deviceProp.maxThreadsDim[1],
////			deviceProp.maxThreadsDim[2]);


		m_genericstr.Format(_T("  Max dimension size of a grid size    (x,y,z): (%d, %d, %d)"),
			deviceProp.maxGridSize[0], deviceProp.maxGridSize[1],
			deviceProp.maxGridSize[2]);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Max dimension size of a grid size    (x,y,z): (%d, %d, %d)\n",
////			deviceProp.maxGridSize[0], deviceProp.maxGridSize[1],
////			deviceProp.maxGridSize[2]);


		m_genericstr.Format(_T("  Maximum memory pitch:                          %lu bytes"),
			deviceProp.memPitch);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Maximum memory pitch:                          %lu bytes\n",
////			devi
		ceProp.memPitch);

		m_genericstr.Format(_T("  Texture alignment:                             %lu bytes"),
			deviceProp.textureAlignment);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Texture alignment:                             %lu bytes\n",
////			deviceProp.textureAlignment);


		m_genericstr.Format(_T("  Concurrent copy and kernel execution:          %S with %d copy engine(s)"),
			(deviceProp.deviceOverlap ? "Yes" : "No"), deviceProp.asyncEngineCount);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf(
////			"  Concurrent copy and kernel execution:          %s with %d copy "
////			"engine(s)\n",
////			(deviceProp.deviceOverlap ? "Yes" : "No"), deviceProp.asyncEngineCount);


		m_genericstr.Format(_T("  Run time limit on kernels:                     %S"),
			deviceProp.kernelExecTimeoutEnabled ? "Yes" : "No");

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Run time limit on kernels:                     %s\n",
////			deviceProp.kernelExecTimeoutEnabled ? "Yes" : "No");


		m_genericstr.Format(_T("  Integrated GPU sharing Host Memory:            %S"),
			deviceProp.integrated ? "Yes" : "No");

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Integrated GPU sharing Host Memory:            %s\n",
////			deviceProp.integrated ? "Yes" : "No");


		m_genericstr.Format(_T("  Support host page-locked memory mapping:       %S"),
			deviceProp.canMapHostMemory ? "Yes" : "No");

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Support host page-locked memory mapping:       %s\n",
////			deviceProp.canMapHostMemory ? "Yes" : "No");


		m_genericstr.Format(_T("  Alignment requirement for Surfaces:            %S"),
			deviceProp.surfaceAlignment ? "Yes" : "No");

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Alignment requirement for Surfaces:            %s\n",
////			deviceProp.surfaceAlignment ? "Yes" : "No");


		m_genericstr.Format(_T("  Device has ECC support:                        %S"),
			deviceProp.ECCEnabled ? "Enabled" : "Disabled");

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Device has ECC support:                        %s\n",
////			deviceProp.ECCEnabled ? "Enabled" : "Disabled");

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)

		m_genericstr.Format(_T("  CUDA Device Driver Mode (TCC or WDDM):         %S"),
			deviceProp.tccDriver ? "TCC (Tesla Compute Cluster Driver)"
			: "WDDM (Windows Display Driver Model)");

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  CUDA Device Driver Mode (TCC or WDDM):         %s\n",
////			deviceProp.tccDriver ? "TCC (Tesla Compute Cluster Driver)"
////			: "WDDM (Windows Display Driver Model)");

#endif

		m_genericstr.Format(_T("  Device supports Unified Addressing (UVA):      %S"),
			deviceProp.unifiedAddressing ? "Yes" : "No");

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Device supports Unified Addressing (UVA):      %s\n",
////			deviceProp.unifiedAddressing ? "Yes" : "No");


		m_genericstr.Format(_T("  Device supports Compute Preemption:            %S"),
			deviceProp.computePreemptionSupported ? "Yes" : "No");

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Device supports Compute Preemption:            %s\n",
////			deviceProp.computePreemptionSupported ? "Yes" : "No");


		m_genericstr.Format(_T("  Supports Cooperative Kernel Launch:            %S"),
			deviceProp.cooperativeLaunch ? "Yes" : "No");

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Supports Cooperative Kernel Launch:            %s\n",
////			deviceProp.cooperativeLaunch ? "Yes" : "No");


		m_genericstr.Format(_T("  Supports MultiDevice Co-op Kernel Launch:      %S"),
			deviceProp.cooperativeMultiDeviceLaunch ? "Yes" : "No");

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Supports MultiDevice Co-op Kernel Launch:      %s\n",
////			deviceProp.cooperativeMultiDeviceLaunch ? "Yes" : "No");


		m_genericstr.Format(_T("  Device PCI Domain ID / Bus ID / location ID:   %d / %d / %d"),
			deviceProp.pciDomainID, deviceProp.pciBusID, deviceProp.pciDeviceID);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Device PCI Domain ID / Bus ID / location ID:   %d / %d / %d\n",
////			deviceProp.pciDomainID, deviceProp.pciBusID, deviceProp.pciDeviceID);


		const char *sComputeMode[] =
		{
			"Default (multiple host threads can use ::cudaSetDevice() with device "
			"simultaneously)",
			"Exclusive (only one host thread in one process is able to use "
			"::cudaSetDevice() with this device)",
			"Prohibited (no host thread can use ::cudaSetDevice() with this "
			"device)",
			"Exclusive Process (many threads in one process is able to use "
			"::cudaSetDevice() with this device)",
			"Unknown",
			NULL };

		m_genericstr.Format(_T("  Compute Mode:  < %S >"),
			sComputeMode[deviceProp.computeMode]);

		m_list1.AddString((LPCTSTR)m_genericstr);
////		printf("  Compute Mode:\n");
////		printf("     < %s >\n", sComputeMode[deviceProp.computeMode]);

	}

	// If there are 2 or more GPUs, query to determine whether RDMA is supported
	if (deviceCount >= 2) {
		cudaDeviceProp prop[64];
		int gpuid[64];  // we want to find the first two GPUs that can support P2P
		int gpu_p2p_count = 0;

		for (int i = 0; i < deviceCount; i++)
		{
			checkCudaErrors(cudaGetDeviceProperties(&prop[i], i));

			// Only boards based on Fermi or later can support P2P
			if ((prop[i].major >= 2)
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
				// on Windows (64-bit), the Tesla Compute Cluster driver for windows
				// must be enabled to support this
				&& prop[i].tccDriver
#endif
				)
			{
				// This is an array of P2P capable GPUs
				gpuid[gpu_p2p_count++] = i;
			}
		}

		// Show all the combinations of support P2P GPUs
		int can_access_peer;

		if (gpu_p2p_count >= 2)
		{
			for (int i = 0; i < gpu_p2p_count; i++)
			{
				for (int j = 0; j < gpu_p2p_count; j++)
				{
					if (gpuid[i] == gpuid[j]) {
						continue;
					}
					checkCudaErrors(
						cudaDeviceCanAccessPeer(&can_access_peer, gpuid[i], gpuid[j]));

					m_genericstr.Format(_T("> Peer access from %S (GPU%d) -> %S (GPU%d) : %S"),
						prop[gpuid[i]].name, gpuid[i], prop[gpuid[j]].name, gpuid[j],
						can_access_peer ? "Yes" : "No");

					m_list1.AddString((LPCTSTR)m_genericstr);

////					printf("> Peer access from %s (GPU%d) -> %s (GPU%d) : %s\n",
////						prop[gpuid[i]].name, gpuid[i], prop[gpuid[j]].name, gpuid[j],
////						can_access_peer ? "Yes" : "No");
				}
			}
		}
	}

	// csv masterlog info
	// *****************************
	// exe and CUDA driver name
////	printf("\n");
	std::string sProfileString = "deviceQuery, CUDA Driver = CUDART";
	char cTemp[16];

	// driver version
	sProfileString += ", CUDA Driver Version = ";
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)

////	sprintf_s(cTemp, 10, "%d.%d", driverVersion / 1000, (driverVersion % 100) / 10);

#else

////	snprintf(cTemp, sizeof(cTemp), "%d.%d", driverVersion / 1000,
////		(driverVersion % 100) / 10);

#endif
	sProfileString += cTemp;

	// Runtime version
	sProfileString += ", CUDA Runtime Version = ";
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)

////	sprintf_s(cTemp, 10, "%d.%d", runtimeVersion / 1000, (runtimeVersion % 100) / 10);

#else

////	snprintf(cTemp, sizeof(cTemp), "%d.%d", runtimeVersion / 1000,
////		(runtimeVersion % 100) / 10);

#endif
	sProfileString += cTemp;

	// Device count
	sProfileString += ", NumDevs = ";
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)

////	sprintf_s(cTemp, 10, "%d", deviceCount);

#else

////	snprintf(cTemp, sizeof(cTemp), "%d", deviceCount);

#endif
	sProfileString += cTemp;
	sProfileString += "\n";

////	printf("%s", sProfileString.c_str());

////	printf("Result = PASS\n");

	// finish
////	exit(EXIT_SUCCESS);

}
