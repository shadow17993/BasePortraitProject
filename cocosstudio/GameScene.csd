<GameFile>
  <PropertyGroup Name="GameScene" Type="Scene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="640.0000" Y="960.0000" />
        <Children>
          <AbstractNodeData Name="background" ActionTag="1086176749" Tag="3" IconVisible="False" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" LeftMargin="-191.8080" RightMargin="-192.1920" TopMargin="-295.9680" BottomMargin="-280.0320" ctype="SpriteObjectData">
            <Size X="1024.0000" Y="1536.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="320.1920" Y="487.9680" />
            <Scale ScaleX="0.6413" ScaleY="0.6630" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5003" Y="0.5083" />
            <PreSize X="1.6000" Y="1.6000" />
            <FileData Type="Normal" Path="Stars.jpg" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="background2" ActionTag="-1515651814" Tag="28" IconVisible="False" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" LeftMargin="-190.7840" RightMargin="-193.2160" TopMargin="-292.9921" BottomMargin="-283.0080" ctype="SpriteObjectData">
            <Size X="1024.0000" Y="1536.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="321.2160" Y="484.9920" />
            <Scale ScaleX="0.6286" ScaleY="0.6549" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5019" Y="0.5052" />
            <PreSize X="1.6000" Y="1.6000" />
            <FileData Type="Normal" Path="Stars.jpg" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Platforms" ActionTag="-250261778" Tag="19" IconVisible="True" RightMargin="640.0000" TopMargin="960.0000" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="1.0000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Platforms.csd" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="ball" ActionTag="1865497309" Tag="10" IconVisible="False" LeftMargin="295.0977" RightMargin="294.9023" TopMargin="339.5659" BottomMargin="570.4341" ctype="SpriteObjectData">
            <Size X="50.0000" Y="50.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="320.0977" Y="595.4341" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5002" Y="0.6202" />
            <PreSize X="0.0781" Y="0.0521" />
            <FileData Type="Normal" Path="Ball.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="TimerText" ActionTag="-1415112117" Tag="13" IconVisible="False" HorizontalEdge="LeftEdge" VerticalEdge="TopEdge" LeftMargin="214.3660" RightMargin="325.6340" TopMargin="65.6179" BottomMargin="867.3821" TouchEnable="True" FontSize="20" IsCustomSize="True" LabelText="0" PlaceHolderText="0" MaxLengthText="10" ctype="TextFieldObjectData">
            <Size X="100.0000" Y="27.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="264.3660" Y="880.8821" />
            <Scale ScaleX="4.5049" ScaleY="3.5572" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4131" Y="0.9176" />
            <PreSize X="0.1563" Y="0.0281" />
          </AbstractNodeData>
          <AbstractNodeData Name="startButton" ActionTag="2104918443" Tag="4" IconVisible="False" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" LeftMargin="293.2240" RightMargin="300.7760" TopMargin="752.9760" BottomMargin="171.0240" TouchEnable="True" FontSize="14" ButtonText="Start" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="46.0000" Y="36.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="316.2240" Y="189.0240" />
            <Scale ScaleX="3.1020" ScaleY="2.3430" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4941" Y="0.1969" />
            <PreSize X="0.0719" Y="0.0375" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
            <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="instructionText" ActionTag="2054152971" Tag="22" IconVisible="False" LeftMargin="217.0342" RightMargin="223.9658" TopMargin="322.4937" BottomMargin="453.5063" FontSize="20" LabelText="Avoid the platforms by&#xA;maneuvering the ball &#xA;around them using&#xA;the touch screen. If &#xA;the ball hits a platform&#xA; or the ball moves off &#xA;screen, it's game over.&#xA;" HorizontalAlignmentType="HT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="199.0000" Y="184.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="316.5342" Y="545.5063" />
            <Scale ScaleX="1.9024" ScaleY="2.1309" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4946" Y="0.5682" />
            <PreSize X="0.3109" Y="0.1917" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>