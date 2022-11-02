#pragma once
#include "CustomUserControlCpp.g.h"

namespace winrt::ReactNativeNativeUi::implementation {
struct CustomUserControlCpp : CustomUserControlCppT<CustomUserControlCpp> {
  CustomUserControlCpp();

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
struct CustomUserControlCpp : CustomUserControlCppT<CustomUserControlCpp, implementation::CustomUserControlCpp> {};
} // namespace winrt::ReactNativeNativeUi::factory_implementation
