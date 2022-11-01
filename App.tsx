/**
 * Yi Yang
 * PDM windows version
 * Oct, 2022
 */

import {createDrawerNavigator} from '@react-navigation/drawer';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
const Drawer = createDrawerNavigator();
const Tab = createBottomTabNavigator();

// import {persistor, store} from './components/handle/redux/store'; // original
import { store} from './components/handle/redux/store';
import React, {type PropsWithChildren} from 'react';
import {
  SafeAreaView,
  ScrollView,
  StatusBar,
  StyleSheet,
  Text,
  useColorScheme,
  View,
} from 'react-native';

import Nav from "./components/platform/Nav";
import { Provider } from "react-redux";
import { ActivityIndicator } from "react-native-windows";
// import Drawer from "@react-navigation/drawer/lib/typescript/src/views/modern/Drawer";
// import { PersistGate } from "redux-persist/integration/react";


const App = () => {
  const isDarkMode = useColorScheme() === 'dark';


  return (
    <Provider store={store}>
      {/*<PersistGate loading={*/}
      {/*  <View >*/}
      {/*    /!*<View style={[styles.centeredView]}>*!/*/}
      {/*    <ActivityIndicator />*/}
      {/*  </View>*/}
      {/*} persistor={persistor}>*/}
        <Nav Drawer={Drawer} Tab={Tab}/>
      {/*</PersistGate>*/}
    </Provider>
  );
};



export default App;
