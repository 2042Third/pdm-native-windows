#include "pch.h"

#include "App.h"
#include "ReactPackageProvider.h"

#include "winrt/NativeModuleSample.h"

namespace winrt::SampleApp::implementation {

App::App() noexcept {
  /* Other Init Code */

  PackageProviders().Append(make<ReactPackageProvider>()); // Includes all modules in this project
  PackageProviders().Append(winrt::NativeModuleSample::ReactPackageProvider());

  /* Other Init Code */
}

} // namespace winrt::SampleApp::implementation
