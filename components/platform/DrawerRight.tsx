// import { createDrawerNavigator, DrawerToggleButton } from "@react-navigation/drawer";
import React, { useEffect } from "react";
import { Alert, Button, SafeAreaView, Text, useWindowDimensions, View } from "react-native-windows";
import { colors, styles } from "../../assets/Style";
// import NotesView from "../views/Notes/NotesPage";
// import CustomDrawerContentRight from "./drawerContent/DrawerContentRight";
// import NotesHeader from "./drawerContent/notes/NotesHeader";
import { useAppSelector } from "../handle/redux/hooks";
import CustomDrawerContentRight from "./drawerContent/DrawerContentRight";
import NotesView from "../views/Notes/NotesPage";
import NotesHeader from "./drawerContent/notes/NotesHeader";
import { NotesHeaderInfo } from "../handle/types";
// const DrawerRightMenu = createDrawerNavigator();

import { NativeModules, NativeEventEmitter } from 'react-native';
const FancyMathEventEmitter = new NativeEventEmitter(NativeModules.FancyMath);

const DrawerRight = () => {
  const window = useWindowDimensions();
  // const header = useAppSelector(state => state.notesHeaderInfo);

  useEffect(()=>{
    // Subscribing to FancyMath.AddEvent
    FancyMathEventEmitter.addListener('AddEvent', eventHandler, this);
    return ()=>{
      // Unsubscribing from FancyMath.AddEvent
      FancyMathEventEmitter.removeListener('AddEvent', eventHandler, this);
    }
  },[]);

  function eventHandler(result) {
    console.log("Event was fired with: " + result);
  }
  const _onPressHandler=()=> {
    // Calling FancyMath.add method
    NativeModules.FancyMath.add(
      /* arg a */ NativeModules.FancyMath.Pi,
      /* arg b */ NativeModules.FancyMath.E,
      /* callback */ function (result) {
        Alert.alert(
          'FancyMath',
          `FancyMath says ${NativeModules.FancyMath.Pi} + ${NativeModules.FancyMath.E} = ${result}`,
          [{ text: 'OK' }],
          {cancelable: false});
      });
  }

  return (
    <View style={[styles.mainColor]}>
      <Text>
        Drawer (that tests windows native modules):
      </Text>

      <Text style={[styles.normalText]}>FancyMath says PI = {NativeModules.FancyMath.Pi}</Text>
      <Text style={[styles.normalText]}>FancyMath says E = {NativeModules.FancyMath.E}</Text>
      <Button  onPress={_onPressHandler} title={"Test Windows Native"}/>
    </View>);
  //   <DrawerRightMenu.Navigator
  //     screenOptions={{
  //       drawerStyle: [styles.drawerStyle, { width: window.width }],
  //       drawerContentStyle: styles.drawerContentStyle,
  //       drawerItemStyle: styles.drawerItemStyle,
  //       drawerInactiveTintColor: colors['--foreground-default'],
  //       drawerType: window.width >= 768 ? 'permanent' : 'slide',
  //       headerShown: true,
  //       drawerPosition: "right",
  //       swipeMinDistance: window.width / 7,
  //       // defaultStatus: window.width >= 768 ? 'open' : 'closed',
  //       swipeEdgeWidth: window.width,
  //     }}
  //     initialRouteName="NotesEdit"
  //     drawerContent={
  //       (props: JSX.IntrinsicAttributes & { [x: string]: any; }) =>
  //         <CustomDrawerContentRight {...props} />}
  //   >
  //     < DrawerRightMenu.Screen
  //       name="NotesEdit"
  //       component={NotesView}
  //       options={(route)=>({
  //         params:{title:""},
  //         lazy: true,
  //         headerStyle: styles.drawerHeaderStyle,
  //         headerTitleStyle: styles.drawerHeaderTitleStyle,
  //         // headerTitle: () => < NotesHeader header={header} />, // original
  //         headerTitle: () => < NotesHeader header={new NotesHeaderInfo()} />,
  //         drawerItemStyle: { display: 'none' },
  //         keyboardDismissMode: "none",
  //         headerLeft: () => null,
  //         headerRight: () => <DrawerToggleButton tintColor={colors['--foreground-default']}/>,
  //
  //       })}/>
  //   </DrawerRightMenu.Navigator>
  //
  // );
}

export default DrawerRight;
