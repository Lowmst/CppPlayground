#pragma once

#include "SamplePage1.g.h"

namespace winrt::WinUI3Playground::implementation
{
    struct SamplePage1 : SamplePage1T<SamplePage1>
    {
        SamplePage1()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::WinUI3Playground::factory_implementation
{
    struct SamplePage1 : SamplePage1T<SamplePage1, implementation::SamplePage1>
    {
    };
}
