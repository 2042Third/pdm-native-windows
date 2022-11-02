#include "pch.h"
#include "CustomUserControl.h"
#include "CustomUserControl.g.cpp"

namespace winrt::ReactNativeNativeUi::implementation {

Windows::UI::Xaml::DependencyProperty CustomUserControl::m_labelProperty =
    Windows::UI::Xaml::DependencyProperty::Register(
        L"Label",
        winrt::xaml_typename<winrt::hstring>(),
        winrt::xaml_typename<winrt::ReactNativeNativeUi::CustomUserControl>(),
        Windows::UI::Xaml::PropertyMetadata{winrt::box_value(winrt::hstring())});

CustomUserControl::CustomUserControl() {
  DefaultStyleKey(winrt::box_value(L"ReactNativeNativeUi.CustomUserControl"));
}

Windows::UI::Xaml::DependencyProperty CustomUserControl::LabelProperty() {
  return m_labelProperty;
}

hstring CustomUserControl::Label() {
  return winrt::unbox_value<winrt::hstring>(GetValue(m_labelProperty));
}

void CustomUserControl::Label(hstring const &value) {
  SetValue(m_labelProperty, winrt::box_value(value));
}

} // namespace winrt::ReactNativeNativeUi::implementation
