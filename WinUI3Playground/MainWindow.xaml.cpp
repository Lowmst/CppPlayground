#include "pch.h"
#include "MainWindow.xaml.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include<vector>


using namespace winrt;
using namespace Microsoft::UI::Xaml;


namespace winrt::WinUI3Playground::implementation
{
	Windows::UI::Xaml::Interop::TypeName hstring2TypeName;
	
	/* 为实现向后导航的栈 */
	std::vector<Controls::NavigationViewItem> NavigatedList;

	/* 将Page的名称(Content、Tag等获取的hstring)映射到对应的TypeName */
	std::unordered_map<hstring, Windows::UI::Xaml::Interop::TypeName> Pages =
	{
		{L"SamplePage1", xaml_typename<winrt::WinUI3Playground::SamplePage1>()},
		{L"SamplePage2", xaml_typename<winrt::WinUI3Playground::SamplePage2>()}
	};

	void MainWindow::InitializeComponent()
	{
		MainWindowT::InitializeComponent();
		contentFrame().Navigate(xaml_typename<winrt::WinUI3Playground::SamplePage1>());
		MainNavigation().SelectedItem(MainNavigation().MenuItems().GetAt(0));
	}
	int32_t MainWindow::MyProperty()
	{
		throw hresult_not_implemented();
	}

	void MainWindow::MyProperty(int32_t /* value */)
	{
		throw hresult_not_implemented();
	}

	/* 只要SelectedItem发生改变就会调用,因此向后导航切换Page后需要pop_back两次 */
	void MainWindow::MainNavigation_SelectionChanged(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewSelectionChangedEventArgs const& args)
	{
		Controls::NavigationViewItem selectedItem = unbox_value<Controls::NavigationViewItem>(args.SelectedItem());

		auto item = unbox_value<hstring>(selectedItem.Content());
		contentFrame().Navigate(Pages[item]);
		NavigatedList.push_back(selectedItem);

	}

	/* 自行实现的后退导航，从NavigatedList中获取上一个Page */
	/* <存在框架自带的实现> */
	void MainWindow::MainNavigation_BackRequested(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewBackRequestedEventArgs const& args)
	{
		if (NavigatedList.size() < 2) {
			return;
		}
		contentFrame().Navigate(Pages[unbox_value<hstring>(NavigatedList.at(NavigatedList.size() - 2).Content())]);
		sender.SelectedItem(NavigatedList.at(NavigatedList.size() - 2));
		NavigatedList.pop_back();
		NavigatedList.pop_back();
	}
}