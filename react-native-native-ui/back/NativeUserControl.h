#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "NativeUserControl.g.h"

namespace winrt::ReactNativeNativeUi::implementation
{
    struct NativeUserControl : NativeUserControlT<NativeUserControl>
    {
        NativeUserControl() {};

        static Windows::UI::Xaml::DependencyProperty LabelProperty();

        hstring Label();
        void Label(hstring const& value);


        static void OnLabelChanged(
            Windows::UI::Xaml::DependencyObject const& d,
            Windows::UI::Xaml::DependencyPropertyChangedEventArgs const& e);


        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    private:
        static Windows::UI::Xaml::DependencyProperty m_labelProperty;
    };
}

namespace winrt::ReactNativeNativeUi::factory_implementation
{
    struct NativeUserControl : NativeUserControlT<NativeUserControl, implementation::NativeUserControl>
    {
    };
}


class CustomUserControl
{
};
