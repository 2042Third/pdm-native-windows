#pragma once
#include "CustomUserControl.g.h"

namespace winrt::ReactNativeNativeUi::implementation {
struct CustomUserControl : CustomUserControlT<CustomUserControl> {
  CustomUserControl();

  static Windows::UI::Xaml::DependencyProperty LabelProperty();

  hstring Label();
  void Label(hstring const &value);

  static void OnLabelChanged(
      Windows::UI::Xaml::DependencyObject const &d,
      Windows::UI::Xaml::DependencyPropertyChangedEventArgs const &e);

 private:
  static Windows::UI::Xaml::DependencyProperty m_labelProperty;
};
} // namespace winrt::ReactNativeNativeUi::implementation

namespace winrt::ReactNativeNativeUi::factory_implementation {
struct CustomUserControl : CustomUserControlT<CustomUserControl, implementation::CustomUserControl> {};
} // namespace winrt::ReactNativeNativeUi::factory_implementation

class CustomUserControl
{
};
