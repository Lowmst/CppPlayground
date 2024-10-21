#include "pch.h"
#include "SamplePage2.xaml.h"
#if __has_include("SamplePage2.g.cpp")
#include "SamplePage2.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::WinUI3Playground::implementation
{
    int32_t SamplePage2::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void SamplePage2::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void SamplePage2::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }
}
