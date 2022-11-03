#include "pch.h"
#include "NativeUserControl.h"
#if __has_include("NativeUserControl.g.cpp")
#include "NativeUserControl.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::ReactNativeNativeUi::implementation
{


    Windows::UI::Xaml::DependencyProperty NativeUserControl::m_labelProperty =
        Windows::UI::Xaml::DependencyProperty::Register(
            L"Label",
            winrt::xaml_typename<winrt::hstring>(),
            winrt::xaml_typename<winrt::ReactNativeNativeUi::NativeUserControl>(),
            Windows::UI::Xaml::PropertyMetadata{ winrt::box_value(winrt::hstring()) });


    NativeUserControl::NativeUserControl() {
        DefaultStyleKey(winrt::box_value(L"ReactNativeNativeUi.NativeUserControl"));
    }

    Windows::UI::Xaml::DependencyProperty NativeUserControl::LabelProperty() {
        return m_labelProperty;
    }

    hstring NativeUserControl::Label() {
        return winrt::unbox_value<winrt::hstring>(GetValue(m_labelProperty));
    }

    void NativeUserControl::Label(hstring const& value) {
        SetValue(m_labelProperty, winrt::box_value(value));
    }

    void NativeUserControl::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
