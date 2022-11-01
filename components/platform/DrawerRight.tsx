// import { createDrawerNavigator, DrawerToggleButton } from "@react-navigation/drawer";
import React from "react";
import { SafeAreaView, Text, useWindowDimensions, View } from 'react-native-windows';
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

const DrawerRight = () => {
  const window = useWindowDimensions();
  // const header = useAppSelector(state => state.notesHeaderInfo);
  return (
    <View><Text>Drawer</Text></View>);
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
