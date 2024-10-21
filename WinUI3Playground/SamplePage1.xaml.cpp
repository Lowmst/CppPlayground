#include "pch.h"
#include "SamplePage1.xaml.h"
#if __has_include("SamplePage1.g.cpp")
#include "SamplePage1.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::WinUI3Playground::implementation
{
    int32_t SamplePage1::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void SamplePage1::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    /*void SamplePage1::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }*/
}
