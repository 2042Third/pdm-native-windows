#pragma once

#include "pch.h"

#include "winrt/Microsoft.ReactNative.h"

namespace winrt::ReactNativeNativeUi::implementation {

struct CustomUserControlViewManager : winrt::implements<
                                             CustomUserControlViewManager,
                                             winrt::Microsoft::ReactNative::IViewManager,
                                             winrt::Microsoft::ReactNative::IViewManagerWithNativeProperties,
                                             winrt::Microsoft::ReactNative::IViewManagerWithCommands,
                                             winrt::Microsoft::ReactNative::IViewManagerWithExportedEventTypeConstants,
                                             winrt::Microsoft::ReactNative::IViewManagerWithReactContext> {
 public:
  CustomUserControlViewManager() = default ;

  // IViewManager
  winrt::hstring Name() noexcept;

  winrt::Windows::UI::Xaml::FrameworkElement CreateView() noexcept;

  // IViewManagerWithNativeProperties
  winrt::Windows::Foundation::Collections::
      IMapView<winrt::hstring, winrt::Microsoft::ReactNative::ViewManagerPropertyType>
      NativeProps() noexcept;

  void UpdateProperties(
      winrt::Windows::UI::Xaml::FrameworkElement const &view,
      winrt::Microsoft::ReactNative::IJSValueReader const &propertyMapReader) noexcept;

  // IViewManagerWithCommands
  winrt::Windows::Foundation::Collections::IVectorView<winrt::hstring> Commands() noexcept;

  void DispatchCommand(
      winrt::Windows::UI::Xaml::FrameworkElement const &view,
      winrt::hstring const &commandId,
      winrt::Microsoft::ReactNative::IJSValueReader const &commandArgsReader) noexcept;

  // IViewManagerWithExportedEventTypeConstants
  winrt::Microsoft::ReactNative::ConstantProviderDelegate ExportedCustomBubblingEventTypeConstants() noexcept;

  winrt::Microsoft::ReactNative::ConstantProviderDelegate ExportedCustomDirectEventTypeConstants() noexcept;

  // IViewManagerWithReactContext
  winrt::Microsoft::ReactNative::IReactContext ReactContext() noexcept;

  void ReactContext(winrt::Microsoft::ReactNative::IReactContext reactContext) noexcept;

private:
  winrt::Microsoft::ReactNative::IReactContext m_reactContext{ nullptr };
};

}
